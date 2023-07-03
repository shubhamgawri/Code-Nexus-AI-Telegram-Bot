import os
import logging
import asyncio
import traceback
import html
import json
import tempfile
import pydub
from pathlib import Path
from datetime import datetime
import openai

import telegram
from telegram import (
    Update,
    User,
    InlineKeyboardButton,
    InlineKeyboardMarkup,
    ReplyKeyboardMarkup,
    KeyboardButton,
    BotCommand
)
from telegram.ext import (
    Application,
    ApplicationBuilder,
    CallbackContext,
    CommandHandler,
    MessageHandler,
    ContextTypes,
    ConversationHandler,
    CallbackQueryHandler,
    AIORateLimiter,
    filters
)
from telegram.constants import ParseMode, ChatAction

import config
import database
import openai_utils


# setup
db = database.Database()
logger = logging.getLogger(__name__)

user_semaphores = {}
user_tasks = {}

HELP_MESSAGE = """Commands:
🔴 /new – Start New Dialog.
🔴 /materials – Get access to study materials.
🔴 /mode – Select Chat Mode.
🔴 /settings – Show Settings.
🔴 /retry – Regenerate Last Bot Answer.
🔴 /balance – Show Balance.
🔴 /help – Show Help.

☕ Get help with <b>Codes</b>, Generate images using 7 different chat modes --> Use /mode
🎤 You can also send <b>Voice Messages</b> instead of text
👥 Add bot to <b>group chat</b>: /help_group_chat
"""

HELP_GROUP_CHAT_MESSAGE = """You can add bot to any <b>group chat</b> to help and entertain its participants!

Instructions (see <b>video</b> below):
1. Add the bot to the group chat
2. Make it an <b>admin</b>, so that it can see messages (all other rights can be restricted)
3. You're awesome!

To get a reply from the bot in the chat – @ <b>tag</b> it or <b>reply</b> to its message.
For example: "{bot_username} write a poem about Telegram"
"""

SUBJECT, MATERIAL, RESOURCE = range(3)

subjects = {
    'Data Structure 🧠': {
        'Practical Labs 💻': {
            '1️⃣ Implementing Stack' : 'resources/DS/1_1_ImplementingStack.c',
            '2️⃣ TwoStacks in One' : 'resources/DS/1_2_TwoStacksinOne.c',
            '3️⃣ Evaluation Of Postfix' : 'resources/DS/2_EvaluationOfPostfix.c',
            '4️⃣ Infix To Postfix' : 'resources/DS/2_Infix_To_Postfix.c',
            '5️⃣ Queue Using Array' : 'resources/DS/2_3_Queue_Using_Array.c',
            '6️⃣ CircularQueue Using Array' : 'resources/DS/4_CircularQueue_Using_Array.c',
            '7️⃣ Linked List' : 'resources/DS/5_Linked_List.c',
            '8️⃣ Two Linked List' : 'resources/DS/6_TwoLinkedList.c',
            '9️⃣ Circular Linked List' : 'resources/DS/7_CircularLinkedList.c',
            '🔟 DFS' : 'resources/DS/10_BFS.c'
        },

         'Notes 📚': {
           'Data Structures in C' : 'resources/DS/DS Complete.pdf',
           'Data Structures in C++' : 'resources/DS/DS in C++.pdf'
        },

         'Resources 📎': {
           'Binary Search Animation' : 'resources/DS/Binary-search.gif',
           'Linear Search Animation' : 'resources/DS/Linear-search.gif',
           'Queue Insert Animation' : 'resources/DS/Q_Insert.gif',
           'Queue Remove Animation' : 'resources/DS/Q_Remove.gif',
           'Stack Pop Animation' : 'resources/DS/S_POP.gif',
           'Stack Push Animation' : 'resources/DS/S_PUSH.gif'
        }
    },

    'Algorithms ⚙': {
        'Practical Labs 💻': {
            '1️⃣ Insertion Sort' : 'resources/AOA/1_InsertionSort.c',
            '2️⃣ Optimised Bubble Sort' : 'resources/AOA/1_OptimisedBubbleSort.c',
            '3️⃣ Selection Sort' : 'resources/AOA/1_SelectionSort.c',
            '4️⃣ Binary Search' : 'resources/AOA/2_BinarySearch.c',
            '5️⃣ Quick Sort' : 'resources/AOA/3_QuickSort.c',
            '6️⃣ Merge Sort' : 'resources/AOA/4_MergeSort.c',
            '7️⃣ Fractional Knapsack' : 'resources/AOA/5_FractionalKnapsack.c',
            '8️⃣ JobSequencing With Deadline' : 'resources/AOA/6_JobSequencingWithDeadline.c',
            '9️⃣ Zero One Knapsack' : 'resources/AOA/7_ZeroOneKnapsack.c',
            '🔟 Floyd Warshall' : 'resources/AOA/8_FloydWarshall.c'
        },
        'Notes 📚': {
            'Algo Notes' : 'resources/AOA/AlgorithmsNotesForProfessionals.pdf'
        },
        'Resources 📎': {
             'Animations' : 'URL to https://workshape.github.io/visual-graph-algorithms/',
             'Tutorials' : 'URL to https://www.programiz.com/dsa',
             'Leetcode Questions' : 'URL to https://drive.google.com/file/d/1MSpPOSWUuqVt9nOHJAJJOj3ULhzJOZAr/view'
        }
    },
    'Python 🐍': {
        'Practical Labs 💻': {
            '1️⃣ Dictionary Highest' : 'resources/PYTHON/1_DictionaryHighest.py',
            '2️⃣ Longest Word' : 'resources/PYTHON/1_LongestWord.py',
            '3️⃣ Merge Dictionary' : 'resources/PYTHON/1_MergeDictionary.py',
            '4️⃣ Prime Factors' : 'resources/PYTHON/1_PrimeFactors.py',
            '5️⃣ Print Dict' : 'resources/PYTHON/1_PrintDict.py',
            '6️⃣ Word Count' : 'resources/PYTHON/1_WordCount.py',
            '7️⃣ Array Sum' : 'resources/PYTHON/2_ArraySum.py',
            '8️⃣ Calculator' : 'resources/PYTHON/2_Calculator.py',
            '9️⃣ Threading' : 'resources/PYTHON/2_Threading.py',
            '🔟 Sum Of Subsets' : 'resources/PYTHON/2_SumOfSubsets.py'
        },

        'Notes 📚': {
            'Notes 📚' : 'resources/PYTHON/PythonNotesForProfessionals.pdf'
        }
    },

    'C/C++ 🍁':  {
        'Practical Labs 💻': {
            '1️⃣ Alphabet Pattern Assignment' : 'resources/CPP/AlphabetPatternAssignment.c',
            '2️⃣ Armstrong Number' : 'resources/CPP/Armstrong_number.c',
            '3️⃣ Array Reverse' : 'resources/CPP/Array_reverse.c',
            '4️⃣ Bubble Sort' : 'resources/CPP/Bubble_Sort.c',
            '5️⃣ Matrix Addition' : 'resources/CPP/MatrixAddn.c',
            '6️⃣ Matrix Multiplication' : 'resources/CPP/MatrixMul.c',
            '7️⃣ Matrix Transpose' : 'resources/CPP/MatrixTranspose.c',
            '8️⃣ Number Pattern' : 'resources/CPP/NumberPattern.c',
            '9️⃣ Reverse Array using Pointer' : 'resources/CPP/RevArrayusingpntr.c',
            '🔟 Star Pattern' : 'resources/CPP/StarPattern.c'
        },
        'Notes 📚': {
           'Data Structures in C 📕' : 'resources/CPP/DS Complete.pdf',
           'Data Structures in C++ 📕' : 'resources/CPP/DS in C++.pdf',
           'C Notes' : 'resources/CPP/CNotesForProfessionals.pdf'
        },
        'Resources 📎': {
           'YT Playlist 📺' : 'URL to https://www.youtube.com/playlist?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O',
           'Linear Search Animation 📺' : 'resources/DS/Linear-search.gif'
        }
    },
    'JAVA ☕':  {
        'Notes 📚': {
            'Full Notes' : 'resources/JAVA/JavaNotesForProfessionals.pdf'
        },

        'Resources 📎': {
          'Compiler Interpreter Diagram' : 'resources/JAVA/c.gif',
           'Access Modifiers in Java' : 'resources/JAVA/Access-Modifiers-in-Java.png'  
        }
    },

    'DBMS 💥': {
        'Resources 📎': {
            'Notes 1' : 'resources/DBMS/PostgreSQLNotesForProfessionals.pdf',
           'Notes 2' : 'resources/DBMS/SQLNotesForProfessionals.pdf'  
        }
    },
    'Operating System 🖥': {
        'Resources 📎': {
            'Notes 📚' : 'URL to https://drive.google.com/file/d/1FAxjhyIlsGGouIyCPyR3xqKVgU7mhEmQ/view',
            'CheatSheet 📃' : 'URL to https://whimsical.com/operating-system-cheatsheet-by-love-babbar-S9tuWBCSQfzoBRF5EDNinQ'
        }
    },
    'Computer Networks 🔗': {
        'Resources 📎': {
            'CheatSheet 📃' : 'URL to https://whimsical.com/networking-cheatsheet-by-love-babbar-FcLExFDezehhfsbDPfZDBv'
        }
    }
}

def split_text_into_chunks(text, chunk_size):
    for i in range(0, len(text), chunk_size):
        yield text[i:i + chunk_size]


async def register_user_if_not_exists(update: Update, context: CallbackContext, user: User):
    if not db.check_if_user_exists(user.id):
        db.add_new_user(
            user.id,
            update.message.chat_id,
            username=user.username,
            first_name=user.first_name,
            last_name= user.last_name
        )
        db.start_new_dialog(user.id)

    if db.get_user_attribute(user.id, "current_dialog_id") is None:
        db.start_new_dialog(user.id)

    if user.id not in user_semaphores:
        user_semaphores[user.id] = asyncio.Semaphore(1)

    if db.get_user_attribute(user.id, "current_model") is None:
        db.set_user_attribute(user.id, "current_model", config.models["available_text_models"][0])

    # back compatibility for n_used_tokens field
    n_used_tokens = db.get_user_attribute(user.id, "n_used_tokens")
    if isinstance(n_used_tokens, int):  # old format
        new_n_used_tokens = {
            "gpt-3.5-turbo": {
                "n_input_tokens": 0,
                "n_output_tokens": n_used_tokens
            }
        }
        db.set_user_attribute(user.id, "n_used_tokens", new_n_used_tokens)

    # voice message transcription
    if db.get_user_attribute(user.id, "n_transcribed_seconds") is None:
        db.set_user_attribute(user.id, "n_transcribed_seconds", 0.0)

    # image generation
    if db.get_user_attribute(user.id, "n_generated_images") is None:
        db.set_user_attribute(user.id, "n_generated_images", 0)


async def is_bot_mentioned(update: Update, context: CallbackContext):
     try:
         message = update.message

         if message.chat.type == "private":
             return True

         if message.text is not None and ("@" + context.bot.username) in message.text:
             return True

         if message.reply_to_message is not None:
             if message.reply_to_message.from_user.id == context.bot.id:
                 return True
     except:
         return True
     else:
         return False


async def start_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    user_id = update.message.from_user.id

    db.set_user_attribute(user_id, "last_interaction", datetime.now())
    db.start_new_dialog(user_id)

    reply_text = "Hi! I'm <b>Code Nexus</b> bot integrated with OpenAI API 🤖\n\n"
    reply_text += HELP_MESSAGE

    await update.message.reply_text(reply_text, parse_mode=ParseMode.HTML)
    await show_chat_modes_handle(update, context)


async def help_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())
    await update.message.reply_text(HELP_MESSAGE, parse_mode=ParseMode.HTML)


async def help_group_chat_handle(update: Update, context: CallbackContext):
     await register_user_if_not_exists(update, context, update.message.from_user)
     user_id = update.message.from_user.id
     db.set_user_attribute(user_id, "last_interaction", datetime.now())

     text = HELP_GROUP_CHAT_MESSAGE.format(bot_username="@" + context.bot.username)

     await update.message.reply_text(text, parse_mode=ParseMode.HTML)
     await update.message.reply_video(config.help_group_chat_video_path)


async def retry_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    dialog_messages = db.get_dialog_messages(user_id, dialog_id=None)
    if len(dialog_messages) == 0:
        await update.message.reply_text("No message to retry 🤷‍♂️")
        return

    last_dialog_message = dialog_messages.pop()
    db.set_dialog_messages(user_id, dialog_messages, dialog_id=None)  # last message was removed from the context

    await message_handle(update, context, message=last_dialog_message["user"], use_new_dialog_timeout=False)


async def message_handle(update: Update, context: CallbackContext, message=None, use_new_dialog_timeout=True):
    # check if bot was mentioned (for group chats)
    if not await is_bot_mentioned(update, context):
        return

    # check if message is edited
    if update.edited_message is not None:
        await edited_message_handle(update, context)
        return

    _message = message or update.message.text

    # remove bot mention (in group chats)
    if update.message.chat.type != "private":
        _message = _message.replace("@" + context.bot.username, "").strip()

    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    chat_mode = db.get_user_attribute(user_id, "current_chat_mode")

    if chat_mode == "artist":
        await generate_image_handle(update, context, message=message)
        return

    async def message_handle_fn():
        # new dialog timeout
        if use_new_dialog_timeout:
            if (datetime.now() - db.get_user_attribute(user_id, "last_interaction")).seconds > config.new_dialog_timeout and len(db.get_dialog_messages(user_id)) > 0:
                db.start_new_dialog(user_id)
                await update.message.reply_text(f"Starting new dialog due to timeout (<b>{config.chat_modes[chat_mode]['name']}</b> mode) ✅", parse_mode=ParseMode.HTML)
        db.set_user_attribute(user_id, "last_interaction", datetime.now())

        # in case of CancelledError
        n_input_tokens, n_output_tokens = 0, 0
        current_model = db.get_user_attribute(user_id, "current_model")

        try:
            # send placeholder message to user
            placeholder_message = await update.message.reply_text("...")

            # send typing action
            await update.message.chat.send_action(action="typing")

            if _message is None or len(_message) == 0:
                 await update.message.reply_text("🥲 You sent <b>empty message</b>. Please, try again!", parse_mode=ParseMode.HTML)
                 return

            dialog_messages = db.get_dialog_messages(user_id, dialog_id=None)
            parse_mode = {
                "html": ParseMode.HTML,
                "markdown": ParseMode.MARKDOWN
            }[config.chat_modes[chat_mode]["parse_mode"]]

            chatgpt_instance = openai_utils.ChatGPT(model=current_model)
            if config.enable_message_streaming:
                gen = chatgpt_instance.send_message_stream(_message, dialog_messages=dialog_messages, chat_mode=chat_mode)
            else:
                answer, (n_input_tokens, n_output_tokens), n_first_dialog_messages_removed = await chatgpt_instance.send_message(
                    _message,
                    dialog_messages=dialog_messages,
                    chat_mode=chat_mode
                )

                async def fake_gen():
                    yield "finished", answer, (n_input_tokens, n_output_tokens), n_first_dialog_messages_removed

                gen = fake_gen()

            prev_answer = ""
            async for gen_item in gen:
                status, answer, (n_input_tokens, n_output_tokens), n_first_dialog_messages_removed = gen_item

                answer = answer[:4096]  # telegram message limit

                # update only when 100 new symbols are ready
                if abs(len(answer) - len(prev_answer)) < 100 and status != "finished":
                    continue

                try:
                    await context.bot.edit_message_text(answer, chat_id=placeholder_message.chat_id, message_id=placeholder_message.message_id, parse_mode=parse_mode)
                except telegram.error.BadRequest as e:
                    if str(e).startswith("Message is not modified"):
                        continue
                    else:
                        await context.bot.edit_message_text(answer, chat_id=placeholder_message.chat_id, message_id=placeholder_message.message_id)

                await asyncio.sleep(0.01)  # wait a bit to avoid flooding

                prev_answer = answer

            # update user data
            new_dialog_message = {"user": _message, "bot": answer, "date": datetime.now()}
            db.set_dialog_messages(
                user_id,
                db.get_dialog_messages(user_id, dialog_id=None) + [new_dialog_message],
                dialog_id=None
            )

            db.update_n_used_tokens(user_id, current_model, n_input_tokens, n_output_tokens)

        except asyncio.CancelledError:
            # note: intermediate token updates only work when enable_message_streaming=True (config.yml)
            db.update_n_used_tokens(user_id, current_model, n_input_tokens, n_output_tokens)
            raise

        except Exception as e:
            error_text = f"Something went wrong during completion. Reason: {e}"
            logger.error(error_text)
            await update.message.reply_text(error_text)
            return

        # send message if some messages were removed from the context
        if n_first_dialog_messages_removed > 0:
            if n_first_dialog_messages_removed == 1:
                text = "✍️ <i>Note:</i> Your current dialog is too long, so your <b>first message</b> was removed from the context.\n Send /new command to start new dialog"
            else:
                text = f"✍️ <i>Note:</i> Your current dialog is too long, so <b>{n_first_dialog_messages_removed} first messages</b> were removed from the context.\n Send /new command to start new dialog"
            await update.message.reply_text(text, parse_mode=ParseMode.HTML)

    async with user_semaphores[user_id]:
        task = asyncio.create_task(message_handle_fn())
        user_tasks[user_id] = task

        try:
            await task
        except asyncio.CancelledError:
            await update.message.reply_text("✅ Canceled", parse_mode=ParseMode.HTML)
        else:
            pass
        finally:
            if user_id in user_tasks:
                del user_tasks[user_id]


async def is_previous_message_not_answered_yet(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)

    user_id = update.message.from_user.id
    if user_semaphores[user_id].locked():
        text = "⏳ Please <b>wait</b> for a reply to the previous message\n"
        text += "Or you can /cancel it"
        await update.message.reply_text(text, reply_to_message_id=update.message.id, parse_mode=ParseMode.HTML)
        return True
    else:
        return False


async def voice_message_handle(update: Update, context: CallbackContext):
    # check if bot was mentioned (for group chats)
    if not await is_bot_mentioned(update, context):
        return

    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    voice = update.message.voice
    with tempfile.TemporaryDirectory() as tmp_dir:
        tmp_dir = Path(tmp_dir)
        voice_ogg_path = tmp_dir / "voice.ogg"

        # download
        voice_file = await context.bot.get_file(voice.file_id)
        await voice_file.download_to_drive(voice_ogg_path)

        # convert to mp3
        voice_mp3_path = tmp_dir / "voice.mp3"
        pydub.AudioSegment.from_file(voice_ogg_path).export(voice_mp3_path, format="mp3")

        # transcribe
        with open(voice_mp3_path, "rb") as f:
            transcribed_text = await openai_utils.transcribe_audio(f)

            if transcribed_text is None:
                 transcribed_text = ""

    text = f"🎤: <i>{transcribed_text}</i>"
    await update.message.reply_text(text, parse_mode=ParseMode.HTML)

    # update n_transcribed_seconds
    db.set_user_attribute(user_id, "n_transcribed_seconds", voice.duration + db.get_user_attribute(user_id, "n_transcribed_seconds"))

    await message_handle(update, context, message=transcribed_text)


async def generate_image_handle(update: Update, context: CallbackContext, message=None):
    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    await update.message.chat.send_action(action="upload_photo")

    message = message or update.message.text

    try:
        image_urls = await openai_utils.generate_images(message, n_images=config.return_n_generated_images)
    except openai.error.InvalidRequestError as e:
        if str(e).startswith("Your request was rejected as a result of our safety system"):
            text = "🥲 Your request <b>doesn't comply</b> with OpenAI's usage policies.\nWhat did you write there, huh?"
            await update.message.reply_text(text, parse_mode=ParseMode.HTML)
            return
        else:
            raise

    # token usage
    db.set_user_attribute(user_id, "n_generated_images", config.return_n_generated_images + db.get_user_attribute(user_id, "n_generated_images"))

    for i, image_url in enumerate(image_urls):
        await update.message.chat.send_action(action="upload_photo")
        await update.message.reply_photo(image_url, parse_mode=ParseMode.HTML)


async def new_dialog_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    db.start_new_dialog(user_id)
    await update.message.reply_text("Starting new dialog ✅")

    chat_mode = db.get_user_attribute(user_id, "current_chat_mode")
    await update.message.reply_text(f"{config.chat_modes[chat_mode]['welcome_message']}", parse_mode=ParseMode.HTML)

async def show_study_materials(update: Update, context: CallbackContext):
    buttons = [KeyboardButton(subject) for subject in subjects]
    buttons.append(KeyboardButton('I want to share my materials 📘'))
    reply_markup = ReplyKeyboardMarkup(build_keyboard(buttons, 2), one_time_keyboard=True)
    await update.message.reply_text('Select a subject: (Use /end to end)', reply_markup=reply_markup)
    return SUBJECT

# Handle subject selection
async def select_subject(update: Update, context: CallbackContext):
    text = update.message.text
    context.user_data['subject'] = text
    if text == 'I want to share my materials 📘':
        await update.message.reply_text('You can send your own study resources to @Shubhamsg09. After review, we can add them to the bot. Thanks for sharing!')
    elif text in subjects:
        buttons = [KeyboardButton(material) for material in subjects[context.user_data['subject']]]
        buttons.append(KeyboardButton('Back 🔙'))
        reply_markup = ReplyKeyboardMarkup(build_keyboard(buttons, 1), one_time_keyboard=True)
        await update.message.reply_text('Select a material: (Use /end to end)', reply_markup=reply_markup)
        return MATERIAL
    else:
        await update.message.reply_text('Invalid subject selected.')
    return ConversationHandler.END

# Handle material selection
async def select_material(update: Update, context: CallbackContext):
    text = update.message.text
    context.user_data['material'] = text
    subject = context.user_data['subject']
    if text == 'Back 🔙':
        return await show_study_materials(update, context)
    elif subject in subjects and text in subjects[subject]:
        keyboard = [[KeyboardButton(resource)] for resource in subjects[context.user_data['subject']][text]]
        keyboard.append([KeyboardButton('Home 🔝'), KeyboardButton('Back 🔙')])
        reply_markup = ReplyKeyboardMarkup(keyboard, one_time_keyboard=True)
        await update.message.reply_text('Select a resource: (Use /end to end)', reply_markup=reply_markup)
        return RESOURCE
    else:
        await update.message.reply_text('Invalid material selected.')
    return ConversationHandler.END

# Handle resource selection
async def select_resource(update: Update, context: CallbackContext):
    text = update.message.text
    subject = context.user_data['subject']
    material = context.user_data['material']
    if text == 'Back 🔙':
        buttons = [KeyboardButton(material) for material in subjects[subject]]
        buttons.append(KeyboardButton('Back 🔙'))
        reply_markup = ReplyKeyboardMarkup(build_keyboard(buttons, 1), one_time_keyboard=True)
        await update.message.reply_text('Select a material: (Use /end to end)', reply_markup=reply_markup)
        return MATERIAL
    elif text == 'Home 🔝':
        return await show_study_materials(update, context)
    elif subject in subjects and material in subjects[subject] and text in subjects[subject][material]:
        location = subjects[subject][material][text]
        if location.startswith('URL to'):
            url = location.split('URL to')[1].strip()
            await update.message.reply_text(f'Here is your <a href="{url}">Link</a> to the resource. Use /materials to request again!', parse_mode='HTML')
        else:
         await context.bot.send_document(chat_id=update.message.chat_id, document=open(location, 'rb'))
         await update.message.reply_text('Thank you for using our resources. Use /materials to request again!')    
    else:
        await update.message.reply_text('Invalid resource selection.')
    return ConversationHandler.END

# Build a 2D keyboard layout with the specified number of columns
def build_keyboard(buttons, n_cols):
    keyboard = [buttons[i:i + n_cols] for i in range(0, len(buttons), n_cols)]
    return keyboard

async def cancel_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    if user_id in user_tasks:
        task = user_tasks[user_id]
        task.cancel()
    else:
        await update.message.reply_text("<i>Nothing to cancel...</i>", parse_mode=ParseMode.HTML)


def get_chat_mode_menu(page_index: int):
    n_chat_modes_per_page = config.n_chat_modes_per_page
    text = f"Select <b>chat mode</b> ({len(config.chat_modes)} modes available):"

    # buttons
    chat_mode_keys = list(config.chat_modes.keys())
    page_chat_mode_keys = chat_mode_keys[page_index * n_chat_modes_per_page:(page_index + 1) * n_chat_modes_per_page]

    keyboard = []
    for chat_mode_key in page_chat_mode_keys:
        name = config.chat_modes[chat_mode_key]["name"]
        keyboard.append([InlineKeyboardButton(name, callback_data=f"set_chat_mode|{chat_mode_key}")])

    # pagination
    if len(chat_mode_keys) > n_chat_modes_per_page:
        is_first_page = (page_index == 0)
        is_last_page = ((page_index + 1) * n_chat_modes_per_page >= len(chat_mode_keys))

        if is_first_page:
            keyboard.append([
                InlineKeyboardButton("»", callback_data=f"show_chat_modes|{page_index + 1}")
            ])
        elif is_last_page:
            keyboard.append([
                InlineKeyboardButton("«", callback_data=f"show_chat_modes|{page_index - 1}"),
            ])
        else:
            keyboard.append([
                InlineKeyboardButton("«", callback_data=f"show_chat_modes|{page_index - 1}"),
                InlineKeyboardButton("»", callback_data=f"show_chat_modes|{page_index + 1}")
            ])

    reply_markup = InlineKeyboardMarkup(keyboard)

    return text, reply_markup


async def show_chat_modes_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    text, reply_markup = get_chat_mode_menu(0)
    await update.message.reply_text(text, reply_markup=reply_markup, parse_mode=ParseMode.HTML)


async def show_chat_modes_callback_handle(update: Update, context: CallbackContext):
     await register_user_if_not_exists(update.callback_query, context, update.callback_query.from_user)
     if await is_previous_message_not_answered_yet(update.callback_query, context): return

     user_id = update.callback_query.from_user.id
     db.set_user_attribute(user_id, "last_interaction", datetime.now())

     query = update.callback_query
     await query.answer()

     page_index = int(query.data.split("|")[1])
     if page_index < 0:
         return

     text, reply_markup = get_chat_mode_menu(page_index)
     try:
         await query.edit_message_text(text, reply_markup=reply_markup, parse_mode=ParseMode.HTML)
     except telegram.error.BadRequest as e:
         if str(e).startswith("Message is not modified"):
             pass


async def set_chat_mode_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update.callback_query, context, update.callback_query.from_user)
    user_id = update.callback_query.from_user.id

    query = update.callback_query
    await query.answer()

    chat_mode = query.data.split("|")[1]

    db.set_user_attribute(user_id, "current_chat_mode", chat_mode)
    db.start_new_dialog(user_id)

    await context.bot.send_message(
        update.callback_query.message.chat.id,
        f"{config.chat_modes[chat_mode]['welcome_message']}",
        parse_mode=ParseMode.HTML
    )


def get_settings_menu(user_id: int):
    current_model = db.get_user_attribute(user_id, "current_model")
    text = config.models["info"][current_model]["description"]

    text += "\n\n"
    score_dict = config.models["info"][current_model]["scores"]
    for score_key, score_value in score_dict.items():
        text += "🟢" * score_value + "⚪️" * (5 - score_value) + f" – {score_key}\n\n"

    text += "\nSelect <b>model</b>:"

    # buttons to choose models
    buttons = []
    for model_key in config.models["available_text_models"]:
        title = config.models["info"][model_key]["name"]
        if model_key == current_model:
            title = "✅ " + title

        buttons.append(
            InlineKeyboardButton(title, callback_data=f"set_settings|{model_key}")
        )
    reply_markup = InlineKeyboardMarkup([buttons])

    return text, reply_markup


async def settings_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)
    if await is_previous_message_not_answered_yet(update, context): return

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    text, reply_markup = get_settings_menu(user_id)
    await update.message.reply_text(text, reply_markup=reply_markup, parse_mode=ParseMode.HTML)


async def set_settings_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update.callback_query, context, update.callback_query.from_user)
    user_id = update.callback_query.from_user.id

    query = update.callback_query
    await query.answer()

    _, model_key = query.data.split("|")
    db.set_user_attribute(user_id, "current_model", model_key)
    db.start_new_dialog(user_id)

    text, reply_markup = get_settings_menu(user_id)
    try:
        await query.edit_message_text(text, reply_markup=reply_markup, parse_mode=ParseMode.HTML)
    except telegram.error.BadRequest as e:
        if str(e).startswith("Message is not modified"):
            pass


async def show_balance_handle(update: Update, context: CallbackContext):
    await register_user_if_not_exists(update, context, update.message.from_user)

    user_id = update.message.from_user.id
    db.set_user_attribute(user_id, "last_interaction", datetime.now())

    # count total usage statistics
    total_n_spent_dollars = 0
    total_n_used_tokens = 0

    n_used_tokens_dict = db.get_user_attribute(user_id, "n_used_tokens")
    n_generated_images = db.get_user_attribute(user_id, "n_generated_images")
    n_transcribed_seconds = db.get_user_attribute(user_id, "n_transcribed_seconds")

    details_text = "🏷️ Details:\n"
    for model_key in sorted(n_used_tokens_dict.keys()):
        n_input_tokens, n_output_tokens = n_used_tokens_dict[model_key]["n_input_tokens"], n_used_tokens_dict[model_key]["n_output_tokens"]
        total_n_used_tokens += n_input_tokens + n_output_tokens

        n_input_spent_dollars = config.models["info"][model_key]["price_per_1000_input_tokens"] * (n_input_tokens / 1000)
        n_output_spent_dollars = config.models["info"][model_key]["price_per_1000_output_tokens"] * (n_output_tokens / 1000)
        total_n_spent_dollars += n_input_spent_dollars + n_output_spent_dollars

        details_text += f"- {model_key}: <b>{n_input_spent_dollars + n_output_spent_dollars:.03f}$</b> / <b>{n_input_tokens + n_output_tokens} tokens</b>\n"

    # image generation
    image_generation_n_spent_dollars = config.models["info"]["dalle-2"]["price_per_1_image"] * n_generated_images
    if n_generated_images != 0:
        details_text += f"- DALL·E 2 (image generation): <b>{image_generation_n_spent_dollars:.03f}$</b> / <b>{n_generated_images} generated images</b>\n"

    total_n_spent_dollars += image_generation_n_spent_dollars

    # voice recognition
    voice_recognition_n_spent_dollars = config.models["info"]["whisper"]["price_per_1_min"] * (n_transcribed_seconds / 60)
    if n_transcribed_seconds != 0:
        details_text += f"- Whisper (voice recognition): <b>{voice_recognition_n_spent_dollars:.03f}$</b> / <b>{n_transcribed_seconds:.01f} seconds</b>\n"

    total_n_spent_dollars += voice_recognition_n_spent_dollars


    text = f"You spent <b>{total_n_spent_dollars:.03f}$</b>\n"
    text += f"You used <b>{total_n_used_tokens}</b> tokens\n\n"
    text += details_text

    await update.message.reply_text(text, parse_mode=ParseMode.HTML)


async def edited_message_handle(update: Update, context: CallbackContext):
    text = "🥲 Unfortunately, message <b>editing</b> is not supported"
    await update.edited_message.reply_text(text, parse_mode=ParseMode.HTML)


async def error_handle(update: Update, context: CallbackContext) -> None:
    logger.error(msg="Exception while handling an update:", exc_info=context.error)

    try:
        # collect error message
        tb_list = traceback.format_exception(None, context.error, context.error.__traceback__)
        tb_string = "".join(tb_list)
        update_str = update.to_dict() if isinstance(update, Update) else str(update)
        message = (
            f"An exception was raised while handling an update\n"
            f"<pre>update = {html.escape(json.dumps(update_str, indent=2, ensure_ascii=False))}"
            "</pre>\n\n"
            f"<pre>{html.escape(tb_string)}</pre>"
        )

        # split text into multiple messages due to 4096 character limit
        for message_chunk in split_text_into_chunks(message, 4096):
            try:
                await context.bot.send_message(update.effective_chat.id, message_chunk, parse_mode=ParseMode.HTML)
            except telegram.error.BadRequest:
                # answer has invalid characters, so we send it without parse_mode
                await context.bot.send_message(update.effective_chat.id, message_chunk)
    except:
        await context.bot.send_message(update.effective_chat.id, "Some error in error handler")

async def post_init(application: Application):
    await application.bot.set_my_commands([
        BotCommand("/new", "Start new dialog"),
        BotCommand("/materials", "Get access to study materials."),
        BotCommand("/mode", "Select chat mode"),
        BotCommand("/retry", "Re-generate response for previous query"),
        BotCommand("/balance", "Show balance"),
        BotCommand("/settings", "Show settings"),
        BotCommand("/help", "Show help message"),
    ])

def run_bot() -> None:
    application = (
        ApplicationBuilder()
        .token(config.telegram_token)
        .concurrent_updates(True)
        .rate_limiter(AIORateLimiter(max_retries=5))
        .post_init(post_init)
        .build()
    )

    # add handlers
    user_filter = filters.ALL
    if len(config.allowed_telegram_usernames) > 0:
        usernames = [x for x in config.allowed_telegram_usernames if isinstance(x, str)]
        user_ids = [x for x in config.allowed_telegram_usernames if isinstance(x, int)]
        user_filter = filters.User(username=usernames) | filters.User(user_id=user_ids)

    application.add_handler(CommandHandler("start", start_handle, filters=user_filter))
    application.add_handler(CommandHandler("help", help_handle, filters=user_filter))
    application.add_handler(CommandHandler("help_group_chat", help_group_chat_handle, filters=user_filter))
    application.add_handler(ConversationHandler(
    entry_points=[CommandHandler('materials', show_study_materials)],
    states={
        SUBJECT: [MessageHandler(filters.TEXT & (~filters.COMMAND) & user_filter, select_subject)],
        MATERIAL: [MessageHandler(filters.TEXT & (~filters.COMMAND) & user_filter, select_material)],
        RESOURCE: [MessageHandler(filters.TEXT & (~filters.COMMAND) & user_filter, select_resource)]
    },
    fallbacks=[CommandHandler('end', select_material)],
    allow_reentry=True
))

    application.add_handler(MessageHandler(filters.TEXT & ~filters.COMMAND & user_filter, message_handle))
    application.add_handler(CommandHandler("retry", retry_handle, filters=user_filter))
    application.add_handler(CommandHandler("new", new_dialog_handle, filters=user_filter))
    application.add_handler(CommandHandler("cancel", cancel_handle, filters=user_filter))

    application.add_handler(MessageHandler(filters.VOICE & user_filter, voice_message_handle))

    application.add_handler(CommandHandler("mode", show_chat_modes_handle, filters=user_filter))
    application.add_handler(CallbackQueryHandler(show_chat_modes_callback_handle, pattern="^show_chat_modes"))
    application.add_handler(CallbackQueryHandler(set_chat_mode_handle, pattern="^set_chat_mode"))

    application.add_handler(CommandHandler("settings", settings_handle, filters=user_filter))
    application.add_handler(CallbackQueryHandler(set_settings_handle, pattern="^set_settings"))

    application.add_handler(CommandHandler("balance", show_balance_handle, filters=user_filter))

    application.add_error_handler(error_handle)

    # start the bot
    application.run_polling()


if __name__ == "__main__":
    run_bot()
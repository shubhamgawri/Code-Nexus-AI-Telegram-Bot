# Code Nexus - AI Telegram Bot: **Integrated with Chat GPT**

## Features
- Added: Access to study resources, lab manuals, and other helpful resources related to coding.
- Added: You can request to add your resources in the bot.
- Edited: 7 different chat modes including Code Assistant, SQL Assistant, etc.
- Low latency replies (it usually takes about 3-5 seconds)
- No request limits
- GPT-4 support
- Group Chat support (/help_group_chat to get instructions)
- DALLE 2 (choose 👩‍🎨 Artist mode to generate images)
- Voice message recognition
- Code highlighting
- 7 special chat modes: 👩🏼‍🎓 Assistant, 👩🏼‍💻 Code Assistant, 👩‍🎨 Artist, and other. You can easily create your own chat modes by editing `config/chat_modes.yml`
- Support of [ChatGPT API](https://platform.openai.com/docs/guides/chat/introduction)
- List of allowed Telegram users
- Track $ balance spent on OpenAI API

---

## Bot commands
- `/materials` – Get access to study resources
- `/retry` – Regenerate last bot answer
- `/new` – Start new dialog
- `/mode` – Select chat mode
- `/balance` – Show balance
- `/settings` – Show settings
- `/help` – Show help

## Setup
1. Get your [OpenAI API](https://openai.com/api/) key

2. Get your Telegram bot token from [@BotFather](https://t.me/BotFather)

3. Edit `config/config.example.yml` to set your tokens and run 2 commands below (*if you're advanced user, you can also edit* `config/config.example.env`):
    ```bash
    mv config/config.example.yml config/config.yml
    mv config/config.example.env config/config.env
    ```

4. 🔥 And now **run**:
    ```bash
    docker-compose --env-file config/config.env up --build
    ```
    
## References
1. Forked ;)

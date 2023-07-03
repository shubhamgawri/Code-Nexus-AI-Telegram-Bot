class Calc:
 def __init__(self, ui):
 self.l1 = self.interpret_it(ui)
 def compute(self):
 print(self.l1)
 if len(self.l1) == 3:
 if self.l1[1] == "+":
 print(self.add_it())
 elif self.l1[1] == "-":\
 print(self.subtract_it())
 else:
 raise Exception("only binaries allowed")
 def add_it(self):
 return int(self.l1[0]) + int(self.l1[2])
 def subtract_it(self):
 if self.l1[0] > self.l1[2]:
 return int(self.l1[0]) - int(self.l1[2])
 elif self.l1[2] > self.l1[0]:
 return int(self.l1[2]) - int(self.l1[0])
 else:
 return 0
 def interpret_it(self, user_inp):
 l2 = [x for x in user_inp]
 return l2
if __name__ == "__main__":
 user = input("enter a binary equation:")
 obj = Calc(user)
 try:
 obj.compute()
 except:
 print("only binary's allowed")
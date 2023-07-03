class Target:
 def __init__(self, target):
  self.target = target
  self.idx = []
 def looper(self, arr):
  for i in range(len(arr)):
   for j in range(len(arr)):
    if j < len(arr) - 1:
     x = arr[i] + arr[j + 1]
     if self.checkit(x):
       self.idx.append([i, j + 1])
 def checkit(self, val):
  if val == self.target:
   return True
if __name__ == '__main__':
 sample = [1, 2, 3, 4, 5, 6, 7, 8, 9]
ui = int(input("enter a target value:"))
obj = Target(ui)
obj.looper(sample)
print(obj.idx)
import threading
k = -1
def is_prime(num, low, high):
 for i in range(low, high):
  print(i)
  if num % i == 0:
   global k
   k += 1
  break

if __name__ == '__main__':
 n = int(input("enter a number: "))
 mid = int(n / 2)
 print(mid)
 try:
  t1 = threading.Thread(target=is_prime, args=(n, 2, mid + 1,))
  t2 = threading.Thread(target=is_prime, args=(n, mid + 1, n,))
  t1.start()
  t2.start()
 except:
  print("Error: unable to start thread")
  if k == -1:
   print("\nprime")
  else:
   print("not prime")
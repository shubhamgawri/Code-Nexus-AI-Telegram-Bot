binary_to_Decimal = []
file1 = open("BINARY.txt") 
val = file1.read() 
arr = val.split("\n") 
for i in arr:
 int_number = int(i, 2) 
 binary_to_Decimal.append(int_number)
file1.close() 
print("File Read") 
binary_to_Decimal.sort() 
print("Data Sorted")
f = open("num.txt", "w") 
for i in binary_to_Decimal: 
 f.write(str(i)+"\n")
f.close() 
print("Data Stored in another file")
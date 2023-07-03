array = []
n = int(input("Enter number of elements in array: "))
for i in range(0, n):
    ele = int(input()) 
    array.append(ele)
arr = [1, 2, 3, 4, 5];     
m = int(input("Enter the number of rotations: "))
print("Original array: ");    
for i in range(0, len(arr)):    
    print(arr[i]),          
for i in range(0, m):    
    last = arr[len(arr)-1];    
        
    for j in range(len(arr)-1, -1, -1):    
        arr[j] = arr[j-1];                      
    arr[0] = last;    
     
print();    
print("Array after right rotation: ");    
for i in range(0, len(arr)):    
    print(arr[i]),  
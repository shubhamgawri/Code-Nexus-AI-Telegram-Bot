n=int(input("Enter an integer:"))
print("Prime Factors are:")
i=1
count=0
while(i<=n):
    k=0
    if(n%i==0):
        j=1
        while(j<=i):
            if(i%j==0):
                k=k+1
            j=j+1
        if(k==2):
            count=count+1  
            print(i)        
    i=i+1
print("Total Count: ", count) 
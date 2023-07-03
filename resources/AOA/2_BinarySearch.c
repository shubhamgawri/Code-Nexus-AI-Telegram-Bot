#include<stdio.h>

  void read(int a[],int n){
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }  
}

 int search(int a[],int l,int h,int x){
     int mid;
     if(l==h){
         if(a[l]==x)
             return l;
             else
             return -1;}
             else{
                 mid=(l+h)/2;
                 if(a[l]==x)
                 return l;
                 else
                 mid =(l+h)/2;
                 if(x==a[mid]){
                     return mid;
                 }
                 else if(x<a[mid]){
                     return(search(a,l,mid-1,x));
                 }
                 else if(x>a[mid]){
                     return(search(a,mid+1,h,x));
                 }
                 }
                 }


void main()
{
 int n,s,l,h,p;
 printf("Enter size of array:");
 scanf("%d",&n);
 int a[n];
 printf("Enter the elements");
 read(a,n);
 printf("Enter search key ");
 scanf("%d",&s);
 l=0,h=n;
 p=search(a,l,h,s);
 if(p!=-1)
 printf("Search key found at the position %d",p+1);
 else
 printf("Search key not found");
}
#include<stdio.h>
#include<conio.h>
typedef struct date
{
  int dd,mm,yy;
 }date;
struct patient{
    date dob;
char First[10], Middle[10], Last[10], disease[10];
} pt[10] ;
int main(){
int i, n ;

printf("Enter the Number of Patients: ");
scanf("%d", &n) ;

for(i = 0 ; i < n ; i++) {
printf("\t\t\tPatient's Details:\n");
printf("\nEnter the Patients DOB (dd-mm-yy): ");
scanf("%d-%d-%d", &pt[i].dob.dd,&pt[i].dob.mm,&pt[i].dob.yy);
printf("\nEnter the First Name: ");
scanf("%s", pt[i].First);
printf("\nEnter the Middle Name: ");
scanf("%s", pt[i].Middle);
printf("\nEnter the Last Name: ");
scanf("%s", pt[i].Last);
printf("\nEnter the Disease Name: ");
scanf("%s", pt[i].disease);
}

printf("\nDOB \t First Name \t Middle Name \t Last Name \t Disease \n\n");

for(i = 0 ; i < n ; i++){
printf("%d-%d-%d \t %s \t %s \t %s \t %s \n", pt[i].dob.dd,pt[i].dob.mm,pt[i].dob.yy,pt[i].First, pt[i].Middle, pt[i].Last, pt[i].disease);
}
return 0;
}
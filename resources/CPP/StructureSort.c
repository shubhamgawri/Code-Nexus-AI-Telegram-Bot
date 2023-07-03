//Program to sort structutre array , FEC, 9371, Shubham Gawri//
#include<stdio.h>
#include<string.h>
struct employee
{
    int empcode;
    char empname[10];
    char designation[30];
    float salary;
}e[3];
void input(struct employee e[]);
void sort(struct employee e[]);
void sortdesignation(struct employee e[]);
void display(struct employee e[]);

int main()
{
 input(e);
 sortdesignation(e);
 sort(e);
 display(e);
 return 0;
}

void input(struct employee e[])
{
    int i;
    printf("Enter the details one by one \n");
    for(i=0;i<3;i++)
    {
        printf("\nEnter code of employee:");
        scanf("%d",&e[i].empcode);
        printf("\nEnter name of employee:");
        scanf("%s",e[i].empname);
        printf("\nEnter designation of employee:");
        scanf("%s",e[i].designation);
        printf("\nEnter salary of employee:");
        scanf("%f",&e[i].salary);
    }
}       
void sort(struct employee e[])
{
    int i,j;
    struct employee temp;
    for(i=0;i<3;i++)
    {
        for(j=0;j<(2-i);j++)
        {
            if(e[j].salary<e[j+1].salary)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;            
            }

        }//for j

    }// for i
}  
void display(struct employee e[])
{
    int i;
    printf("\nEmployee details in descending order of salary\n");
    for(i=0;i<3;i++)
    {
        printf("%d\t %s\t %s\t %f\t",e[i].empcode,e[i].empname,e[i].designation,e[i].salary);
        printf("\n");
    }
}
void sortdesignation(struct employee e[])
{
    int i,j;
    struct employee temp;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2-i;j++)
        {
            if(strcmp(e[j].designation,e[j+1].designation)>0)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;            
            }
        }        
    }    
    printf("\nEmployee details in ascending order of designation\n");
    for(i=0;i<3;i++)
    {
        printf("%d\t %s\t %s\t %f\t",e[i].empcode,e[i].empname,e[i].designation,e[i].salary);
        printf("\n");

    }//for i

}


#include <stdio.h>
#define MAX 100

typedef struct Job
{
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n) 
{
 
  int i, j, k, maxprofit,timeslot[MAX];

  int filledTimeSlot = 0;

  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) 
  {
    if(jobs[i].deadline > dmax) 
    {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 
  for(i = 1; i <= dmax; i++) 
  {
    timeslot[i] = -1;
  }

  printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) 
  {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) 
      {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) 
    {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) 
  {
    printf("%s", jobs[timeslot[i]].id);
    if(i < dmax) 
    {
      printf(" --> ");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}


int minValue(int x, int y)
{
  if(x < y) return x;
  return y;
}

int main() 
{
  
  int i, j,n;
  Job jobs[50],temp;
  printf("Enter the number of jobs : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf ("Enter the job id : ");
    scanf ("%d", &jobs[i].id);
    printf ("Enter the job profit : ");
    scanf ("%d", &jobs[i].profit);
    printf ("Enter the job deadline : ");
    scanf ("%d", &jobs[i].deadline);
  }
  //sort the jobs profit wise in descending order
  for(i = 1; i < n; i++) 
  {
    for(j = 0; j < n - i; j++) 
    {
      if(jobs[j+1].profit > jobs[j].profit) 
      {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) 
  {
    printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencingWithDeadline(jobs, n);

  return 0;
}

/*________________________________OUTPUT_________________________________*/

/*Enter the number of jobs : 7
Enter the job id : 1
Enter the job profit : 35
Enter the job deadline : 3
Enter the job id : 2
Enter the job profit : 30
Enter the job deadline : 4
Enter the job id : 3
Enter the job profit : 25
Enter the job deadline : 4
Enter the job id : 4
Enter the job profit : 20
Enter the job deadline : 2
Enter the job id : 5
Enter the job profit : 15
Enter the job deadline : 3
Enter the job id : 6
Enter the job profit : 12
Enter the job deadline : 1
Enter the job id : 7
Enter the job profit : 5
Enter the job deadline : 2
       Job   Deadline     Profit
         1          3         35
         2          4         30
         3          4         25
         4          2         20
         5          3         15
         6          1         12
         7          2          5
dmax: 4

Required Jobs: 4 --> 3 --> 1 --> 2
Max Profit: 110*/

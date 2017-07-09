#include<stdio.h>
#include<conio.h>
			       //Shortest job first
void sjf(int []);
void avgwt(int []);

void main()
{
 //int bt[5]={10,5,7,9,2},i,j,temp;
 int bt[5],i,j,temp;
 clrscr();

 printf("Enter bus times for processes\n");
 for(i=0;i<5;i++)
 {
  scanf("%d",&bt[i]);
 }

 printf("You entered the following bus times\n");
 for(i=0;i<5;i++)
 {
  printf("p[%d] = %d \n",i,bt[i]);
 }
 for (i=0;i<5;i++)
 {
  for (j=i+1;j<5;j++)
  {
   if (bt[i]>bt[j])
   {
    temp =  bt[i];
    bt[i] = bt[j];
    bt[j] = temp;
   }
  }
 }

 printf("Bus times according to Shortest jobs first\n");
 for(i=0;i<5;i++)
 {
  printf("p[%d] = %d \n",i,bt[i]);
 }
 sjf(bt);
 getch();
}

void sjf(int bt[5])
{
  int wt[5]={0,0,0,0,0},i,j,k=0;

  for(i=0;i<5;i++)
  {
    if(i==0)
    {
     k++;
     continue;
    }
    for(j=0;j<i;j++)
    {
      wt[k]=wt[k]+bt[j];
    }
    k++;
  }

  printf("\nWaiting times for each process are\n");
  for(i=0;i<5;i++)
  {
   printf("p[%d] = %d \n",i,wt[i]);
  }

  avgwt(wt);
}

void avgwt(int wt[5])
{
 int i;
 float avgwt=0;

 for(i=0;i<5;i++)
 {
  avgwt=avgwt+wt[i];
 }

 avgwt=avgwt/5;
 printf("\nAverage Waiting time is %f",avgwt);
}



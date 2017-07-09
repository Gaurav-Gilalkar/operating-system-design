#include<stdio.h>
#include<conio.h>

void sort(int [],int [],int [],int);
void avgwt(int [],int);
void avgtat(int [],int [],int [],int);
int bt[20],p[20],pr[20],n;
float avg_wt,avg_tat;

int main()
{
    int i;
    clrscr();
    printf("Enter Total Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
	printf("\nP[%d]\n",i);
	printf("Burst Time:");
	scanf("%d",&bt[i]);
	printf("Priority:");
	scanf("%d",&pr[i]);
	p[i]=i;           //contains process number
    }


    sort(pr,bt,p,n);
    avgwt(bt,n);


    getch();
    return 0;
}

void sort(int pr[],int bt[],int p[],int n)
{
   int i,j=0,pos,temp=0;
   //sorting burst time, priority and process number in
   //ascending order using selection sort
for(i=0;i<n;i++)
    {
	pos=i;
	for(j=i+1;j<n;j++)
	{
	    if(pr[j]<pr[pos])
		pos=j;
	}

	temp=pr[i];
	pr[i]=pr[pos];
	pr[pos]=temp;

	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
    }
}

void avgwt(int bt[],int n)
{
  int wt[20],i,j,total=0;

  wt[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
	wt[i]=0;
	for(j=0;j<i;j++)
	    wt[i]+=bt[j];

	total+=wt[i];
    }

    avg_wt=total/n;      //average waiting time
    avgtat(bt,wt,p,n) ;
}

void avgtat(int bt[],int wt[],int p[],int n)
{
 int i,tat[20],total=0;
 printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
	tat[i]=bt[i]+wt[i];     //calculate turnaround time
	total+=tat[i];
	printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

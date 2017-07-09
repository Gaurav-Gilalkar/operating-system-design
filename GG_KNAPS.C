#include<stdio.h>
#include<conio.h>

void knapsack();
int n,i,j,cap,k=0;
float ratio[20],price[20],weight[20],profit=0,fraction[20],temp=0;

void main()
{

 clrscr();
 printf("Enter No. of items: ");
 scanf("%d",&n);

 printf("Enter Capacity of Knapsack: ");
 scanf("%d",&cap);



 printf("Enter Prices and Weights\n");
 for(i=0;i<n;i++)
  scanf("%f %f",&price[i],&weight[i]);

  printf("The Maximum profit will be calcualated by greedy approach\n");
  knapsack();
  getch();
}

void knapsack()
{

 float swap=0;
 for(i=0;i<n;i++)
  ratio[i]=price[i]/weight[i];

  for (i=0;i<(n-1);i++)
    for (j=0;j<n-i-1;j++)
      if (ratio[j]<ratio[j+1]) /* For decreasing order use < */
      {
	swap       = ratio[j];
	ratio[j]   = ratio[j+1];
	ratio[j+1] = swap;

	swap       = price[j];
	price[j]   = price[j+1];
	price[j+1] = swap;

	swap       = weight[j];
	weight[j]   = weight[j+1];
	weight[j+1] = swap;
      }

   printf("Sorted ratio is\n");
   for(i=0;i<n;i++)
    printf("%f ",ratio[i]);

//     for(i=0;i<n;i++)
  //  {
     while(cap!=0)
     {
     if(weight[k]>cap)
     {
       fraction[k]=cap/weight[k];
       weight[k]=(weight[k]*cap)/weight[k];
       cap=cap-weight[k];
       temp=(price[k]*fraction[k]);
       profit=profit+temp;
       k++;
     }
     else if(weight[k]==cap)
     {
       fraction[k]=1;
       profit=profit+price[k];
       k++;
       break;
     }
      else
      {
       fraction[k]=1;
       cap=cap-weight[k];
       profit=profit+price[k];
       k++;
      }
    }
   //}
   printf("\nFraction\t\tPrice\t\tWeight \n");
   for(i=0;i<n;i++)
    printf("%f\t%f\t%f\n",fraction[i],price[i],weight[i]);

  printf("\nMaximum profit: %f",profit);

}



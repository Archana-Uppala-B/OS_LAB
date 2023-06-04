#include <stdio.h>
struct process {
	int pn;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};

struct process p[10];

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
 void fcfs(int n)
 {
 	int i,t;
 	for(i=0;i<n;i++)
 	{
 		if(i==0)
 		{
		 p[i].ct=p[i].at+p[i].bt;
 		 t=p[i].ct;
 		 p[i].tat=p[i].ct-p[i].at;
 		 p[i].wt=p[i].tat-p[i].bt;
 		 
     	}
 		else
 		{
 		 p[i].ct=t+p[i].bt;
 		 t=p[i].ct;
 		 p[i].tat=p[i].ct-p[i].at;
 		 p[i].wt=p[i].tat-p[i].bt;
 	    }
	}
	
	for(i=0;i<n;i++)
	{
		printf("P%d %d %d %d %d %d\n",p[i].pn,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	if(p[0].at!=0)
		printf("%s","-Idle-");	
	for(i=0;i<n;i++)
	{
		printf("P%d ",p[i].pn);
	}
	printf("\n");
	if(p[0].at!=0)
	printf("%d     ",0);
	for(i=0;i<n;i++)
	{
		printf("%d  ",p[i].ct);
	}
 }

void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
			
				swap(&p[j].pn,&p[j+1].pn);
			    swap(&p[j].at,&p[j+1].at);
			    swap(&p[j].bt,&p[j+1].bt);

			}
			else if(p[j].at==p[j+1].at)
			{
				if(p[j].pn>p[j+1].pn)
				{
				swap(&p[j].pn,&p[j+1].pn);
			    swap(&p[j].at,&p[j+1].at);
			    swap(&p[j].bt,&p[j+1].bt);
					
				}
			}
		}
	}	
	fcfs(n);
}
int main()
{
	int i,n;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	printf("Enter the pno.,arrival time,burst time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	sort(n);
}

/*
1 25 3
2 5 3
3 3 7
4 2 4
5 5 6
*/

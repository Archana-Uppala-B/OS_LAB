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

void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				int temp=p[j].pn;
				p[j].pn=p[j+1].pn;
				p[j+1].pn=temp;
				
				temp=p[j].at;
				p[j].at=p[j+1].at;
				p[j+1].at=temp;
				
				temp=p[j].bt;
				p[j].bt=p[j+1].bt;
				p[j+1].bt=temp;
				
				
			}
		}
	}
}


int main()
{
	int i,n;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	printf("Enter the pno.,arrival time,burst time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	
	//printing the gantt chart
	
	sort(n);
}


#include <stdio.h>
#include <stdbool.h>

struct process {
	int pn;
	int prio;
	int at;
	int bt;
	int bbt;
	int ct;
	int tat;
	int wt;
	bool x;
};

struct process p[10];

int find_min_prio(int n,int tempct)
{
	int min=1000,i,index=-1;
	for(i=0;i<n;i++)
	{
            if(p[i].x!=true && p[i].at<=tempct)
            {
		      if(p[i].prio<min)
		      {
		        min=p[i].prio;
		        index=i;
		      }
		    }
	}

	return index;
}


void priority(int n)
{
	int count=0;
	int tempct=0,ind;
	while(count!=n)
	{
		ind=find_min_prio(n,tempct);
		
		if(ind==-1)
		{
			printf("-Idle-");
			tempct++;
		}
		else
		{
			printf("P%d ",p[ind].pn);

		    p[ind].bt--;
		    tempct++;
		    
		    if(p[ind].bt==0)
		    {
		    	p[ind].ct=tempct;
		    	p[ind].tat=p[ind].ct-p[ind].at;
		    	p[ind].wt=p[ind].tat-p[ind].bbt;
		    	count++;
		    	p[ind].x=true;
			}
			else
			{
				continue;
			}
		}
	}
	printf("\n");
}

int main()
{
	int i,n;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	
	//default bool is false
	for(i=0;i<n;i++)
	{
		p[i].x=false;
	}
	printf("Enter the pno.,priority,arrival time,burst time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i].pn,&p[i].prio,&p[i].at,&p[i].bt);
	}
	
	for(i=0;i<n;i++)
	{
		p[i].bbt=p[i].bt;
	}
	
	printf("\n\n-----GANTT CHART-----\n");
	priority(n);
	
	printf("\npn		prio		at		bt		ct\n");
	for(i=0;i<n;i++)
	{
		printf("P%d		%d		%d		%d		%d\n",p[i].pn,p[i].prio,p[i].at,p[i].bbt,p[i].ct);
	}
}

/*
1 2 0 4
2 4 1 2
3 6 2 3
4 1 3 5
5 8 4 1
6 3 5 4
7 2 11 6
*/


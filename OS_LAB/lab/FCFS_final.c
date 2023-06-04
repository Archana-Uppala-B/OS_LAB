#include <stdio.h>
#include <stdbool.h>
struct process {
	int pn;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	bool x;
};

struct process p[10];

int find_min_at(int n,int tempct)
{
	int min=100,i,index=-1;
	for(i=0;i<n;i++)
	{
            if(p[i].x!=true && p[i].at<=tempct)
            {
		      if(p[i].at<min)
		      {
		        min=p[i].at;
		        index=i;
		      }
		    }
	}

	return index;
}

void fcfs(int n)
{
	int count=0;
	int tempct=0,ind;
	while(count!=n)
	{
		ind=find_min_at(n,tempct);
		
		if(ind==-1)
		{
			printf("-Idle-");
			tempct++;
		}
		else
		{
			printf("P%d ",p[ind].pn);
			count++;
			p[ind].x=true;
			p[ind].ct=p[ind].bt+tempct;
			tempct=p[ind].ct;
			
			p[ind].tat=p[ind].ct-p[ind].at;
			p[ind].wt=p[ind].tat-p[ind].bt;
		}
	}
	printf("\n");
}


int main()
{
	int i,n;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		p[i].x=false;
	}
	
	printf("Enter the pno.,arrival time,burst time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	
	//sort(n);
	fcfs(n);
	
	for(i=0;i<n;i++)
	{
		printf("P%d %d %d %d %d %d\n",p[i].pn,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	float avgtat=0,avgwt=0;
	
	for(i=0;i<n;i++)
	{
		avgtat=avgtat+p[i].tat;
		avgwt=avgwt+p[i].wt;
	}
	
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	
	printf("\nThe average turn around time is: %0.3f",avgtat);
	printf("\nThe average waiting tie is: %0.3f",avgwt);
}

/*
1 4 4
2 8 2
3 6 3
4 5 3
5 2 1
6 7 7
*/

/*
//this example is with same arrival(at=5)
1 3	4
2 5	3
3 0	2     
4 5	1
5 4	3
*/

/*
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
}
*/

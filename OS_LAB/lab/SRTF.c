#include <stdio.h>
#include <stdbool.h>
struct process {
	int pn;
	int at;
	int bt;
	int bbt;
	int ct;
	int tat;
	int wt;
	bool x;
};

struct process p[10];

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
			
				swap(&p[j].pn,&p[j+1].pn);
			    swap(&p[j].at,&p[j+1].at);
			    swap(&p[j].bt,&p[j+1].bt);
			    swap(&p[j].bbt,&p[j+1].bbt);
			    swap(&p[j].ct,&p[j+1].ct);
			    swap(&p[j].tat,&p[j+1].tat);
			    swap(&p[j].wt,&p[j+1].wt);		    
			}
			else if(p[j].bt==p[j+1].bt)
			{
				if(p[j].at>p[j+1].at)
				{
				swap(&p[j].pn,&p[j+1].pn);
			    swap(&p[j].at,&p[j+1].at);
			    swap(&p[j].bt,&p[j+1].bt);
			    swap(&p[j].bbt,&p[j+1].bbt);
			    swap(&p[j].ct,&p[j+1].ct);
			    swap(&p[j].tat,&p[j+1].tat);
			    swap(&p[j].wt,&p[j+1].wt);
					
				}
				else if(p[j].at==p[j+1].at)
				{
				    if(p[j].pn>p[j+1].pn)
				    {
				       swap(&p[j].pn,&p[j+1].pn);
			           swap(&p[j].at,&p[j+1].at);
			           swap(&p[j].bt,&p[j+1].bt);
			           swap(&p[j].bbt,&p[j+1].bbt);
			           swap(&p[j].ct,&p[j+1].ct);
			           swap(&p[j].tat,&p[j+1].tat);
			           swap(&p[j].wt,&p[j+1].wt);
					}
					
				}
			}
		}
	}
}

int find_min_bt(int n,int tempct)
{
	int min=100,i,index=-1;
	for(i=0;i<n;i++)
	{
            if(p[i].x!=true && p[i].at<=tempct)
            {
		      if(p[i].bt<min)
		      {
		        min=p[i].bt;
		        index=i;
		      }
		    }
	}

	return index;
}

void srtf(int n)
{
	int count=0;
	int tempct=0,ind;
	while(count!=n)
	{
		ind=find_min_bt(n,tempct);
		
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
			//sort(n);
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
	
	for(i=0;i<n;i++)
	{
		p[i].bbt=p[i].bt;
	}
	
	printf("\n\n-----GANTT CHART----\n");
	srtf(n);
	
	printf("\n\npn		at		bt		ct		tat		wt\n");
	for(i=0;i<n;i++)
	{
		printf("P%d		%d		%d		%d		%d		%d\n",p[i].pn,p[i].at,p[i].bbt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	float avgtat=0,avgwt=0;
	for(i=0;i<n;i++)
	{
		avgtat=avgtat+p[i].tat;
		avgwt=avgwt+p[i].wt;
	}
	
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	
	
	printf("\n\nAvg TURNAROUNDTIME is %f\n",avgtat);
	printf("Avg WAITINGTIME is %f\n",avgwt);	
}



/*
check ....
1 0 6
2 1 4
3 2 1
4 3 2
5 4 1
6 5 3 
*/


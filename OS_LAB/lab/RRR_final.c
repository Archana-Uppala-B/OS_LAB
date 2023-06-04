#include <stdio.h>
#include<stdlib.h>
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

int tq;

struct ready_queue{
	int id;
	bool status;
};

struct ready_queue r[100];
int ri=0;

void rr(int n)
{
	int ind=-1,tempct=0;
	int ptempct=-1;
	
	int count=0;
	
	int temp_count=0;
	int i;

	while(count!=n)
	{
		for(i=0;i<n;i++)
	{
		if(p[i].at>ptempct && p[i].at<=tempct && p[i].x==false)
		{
				r[ri].id=i;               //storing index in ready queue...
				r[ri].status=false;
				ri++;
				temp_count++;            //counting the no. of processes in queue
		}
	} 
	
	if(ind!=-1 && p[ind].bt!=0)
	{
		r[ri].id=ind;
		r[ri].status=false;              //storing uncompleted process in queue
		ri++;  
	}
	
	if(temp_count==0)
	{
		printf("--IDLE--");
		ptempct=tempct;
		tempct++;
	}
	else
	{
		for(i=0;i<ri;i++)
		{
			if(r[i].status==false)
			{
				ind=r[i].id;            //index               //picking process index from the ready queue..
				r[i].status=true;
				break;
			}
		}
		printf("P%d |",p[ind].pn);
		if(p[ind].bt<tq)
		{
			ptempct=tempct;
			tempct=tempct+p[ind].bt;
			p[ind].bt=0;
		}
		else
		{
			p[ind].bt=p[ind].bt-tq;
			ptempct=tempct;
			tempct=tempct+tq;
		}
		
		if(p[ind].bt==0)
		{
			count++;
			p[ind].x=true;
		}
	}
    }
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
	
	printf("Enter the time_quantam: ");
	scanf("%d",&tq);
	
	rr(n);
	
	printf("\n--Ready queue--\n");
	for(i=0;i<ri;i++)
	{
		int j=r[i].id;
		printf("P%d |",p[j].pn);
	}
}
/*
1 5 6
2 8 7
3 3 8
4 6 3
5 2 2
6 4 4
*/


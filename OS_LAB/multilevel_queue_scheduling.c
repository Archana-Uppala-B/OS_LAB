#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;

struct process{
	int qno;
	int pno;
	int at;
	int bt;
	int bbt;
	int ct;
	int prio;
	int tat;
	int wt;
	bool stat;
};

struct queue{
	int qno;
	int prio;
	int noOfProcess;
	struct process p;
	int cs;
	bool stat;
};

struct process p1[10];
struct process p2[10];
struct process p3[10];
struct process p4[10];

struct queue que[10];

int find_minqp(int n)
{
	int i;
	int min=100,index=-1;
	for(i=0;i<n;i++)
	{
		if(min>que[i].prio && que[i].stat!=true)
		{
			min=que[i].prio;
			index=i;
		}
	}
	return i;
}


/////copy

int main()
{
	int i,j,ch,a,b,c;
	printf("No. of queues");
	scanf("%d",n);
	
	printf("que_no  que_priority  que_noOfprocesses\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&que[i].qno,&que[i].prio,&que[i].noOfProcess);	
    }
    printf("Process in Queue1");
	for(i=0;i<q[0].noOfProcess;i++)
	 scanf("%d %d %d",&p1[i].at,&p1[i].bt,&p1[i].prio);
	
	printf("Process in Queue2");
	for(i=0;i<q[1].noOfProcess;i++)
	 scanf("%d %d %d",&p2[i].at,&p2[i].bt,&p2[i].prio);
	
	printf("Process in Queue3");
	for(i=0;i<q[2].noOfProcess;i++)
	 scanf("%d %d %d",&p3[i].at,&p3[i].bt,&p3[i].prio);
    
    printf("\n1--FCFS\n2--SJF\n3--PRIORITY\n4--ROUND_ROBIN\n5--SRTF\n6--PREEMPTIVE_PRIORITY");
    for(i=0;i<n;i++)
    {
    	printf("Choice of CPU_Scheduling for queue-%d",i);
    	scanf("%d",&que[i].cs);
    }
    
    int qn=0,minqp;
    while(qn!=n)
    {
    	for(i=0;i<n;i++)
    	{
    		minqp=find_minqp(n);
    		if(minqp!=-1)
    		{
    		   	switch(que[minqp].cs)
    		   	{
    		   		case 1:
    		   			fcfs(que[minqp].noOfProcess);
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		case 2:
    		   			sjf();
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		case 3:
    		   			priority();
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		case 4:
    		   			rr();
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		case 5:
    		   			srtf();
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		case 6:
    		   			preemprive_priority();
    		   			que[minqp].stat=true;
    		   			qn++;
    		   			break;
    		   		
				}
			}
			if(minqp==-1)
			{
				exit();
			}
		}  	
	}
}


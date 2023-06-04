#include <stdio.h>
#include <stdlib.h>

int absolute(int val)
{
	return val+(-2*val);
}

int readyQueue[20];
int finish[20];
int find_min_difference(int n,int curr)
{
	int i,min=1000,index=-1;
	for(i=0;i<n;i++)
	{
		if(curr-readyQueue[i]<0)
		{
			if(min>absolute(curr-readyQueue[i]) && finish[i]==-1)
			{
				min=absolute(curr-readyQueue[i]);
			    index=i;
			}
		}
		else
		{
			if(min>curr-readyQueue[i] && finish[i]==-1)
			{
				min=curr-readyQueue[i];
				index=i;
			}
		}
	}
	return index;
}
int main()
{
	int n;
	int i,seekTime=0,curr;
	printf("Enter the no of requests");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&readyQueue[i]);
		finish[i]=-1;
	}
	printf("Enter the current head position");
	scanf("%d",&curr);
	
	int ind=-1;
	for(i=0;i<n;i++)
	{
		ind=find_min_difference(n,curr);
		printf("%d ",readyQueue[ind]);
		finish[ind]=0;
		if(curr-readyQueue[ind]<0)
		 seekTime+=absolute(curr-readyQueue[ind]);
		else
		 seekTime+=curr-readyQueue[ind];
		
		
		curr=readyQueue[ind];
	}
	
	
	printf("seekTime is %d",seekTime);
}

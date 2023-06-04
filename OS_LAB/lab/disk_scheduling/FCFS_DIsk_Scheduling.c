#include <stdio.h>
#include <stdlib.h>

int absolute(int val)
{
	return val+(-2*val);
}
int main()
{
	int n,i,curr;
	int seekTime=0;
	printf("No. of requests: ");
	scanf("%d",&n);
	int readyqueue[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&readyqueue[i]);
	}
	
	printf("Enter the current disk position: ");
	scanf("%d",&curr);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",readyqueue[i]);
		if(curr-readyqueue[i]<0)
		  seekTime+=absolute(curr-readyqueue[i]);
		else
		 seekTime+=curr-readyqueue[i];
		curr=readyqueue[i];	
	}
	printf("\n\nTotal head momements are %d",seekTime);
}

/*
82 170 43 140 24 16 190
*/

#include <stdio.h>
#include <stdlib.h>

struct frame{
	int in;
	int old;
}; 

int n,fn;
	
struct frame F[10];

int find_oldest()
{
	int min=100,i,index=-1;
	for(i=0;i<fn;i++)
	{
		if(min>F[i].old)
		{
            min=F[i].old;
            index=i;
		}
	}
	return index;	
}

int main()
{
	int i,j,k;
	printf("\nlength of the input string:");
	scanf("%d",&n);
	int input[n];
	printf("\nEnter the input string\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
	}
	
	printf("\nno. of frame:");
	scanf("%d",&fn);
	
	for(i=0;i<fn;i++)
	{
		F[i].in=1000;
		F[i].old=0;
	}
	
	int noOfPageFaults=0;
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<fn;j++)
		{
			if(input[i]==F[j].in)
			{
				printf("\nThe page is not replaced..");
				//no page fault..
				break;
			}
		}
		//if not present in th frame
		//find the oldest frame
		if(j>=fn)
		{
		int ind=find_oldest();
		F[ind].in=input[i];
		F[ind].old++;
		noOfPageFaults++;
		//printf("page fault: %d",noOfPageFaults);
	    }
		
		//printf("%d %d %d\n",F[0].in,F[1].in,F[2].in);
		
		
		for(k=0;k<fn;k++)
		{
			if(F[k].in==1000)
			 printf("_ ");
			else
			 printf("%d ",F[k].in);
		}
		printf("\n");			
	}
	
	printf("\nThe no. of page faults is %d",noOfPageFaults);
	printf("\nThe no. of page replacements is %d",noOfPageFaults-fn);

}
/*
1 2 3 4 1 2 5 1 2 3 4 5
*/

#include <stdio.h>
#include <stdlib.h>

int p,f;
int input[50];
struct frame{
	int in;
	int least;
};

struct frame F[10];

int find_leastRecentOne()
{
	int min=100,index=-1,k;
	for(k=0;k<f;k++)
	{
		if(min>F[k].least)
		{
			min=F[k].least;
			index=k;
		}
	}
	return index;
}

int main()
{
	int i,j;
	printf("\nNo of pages:");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&input[i]);	
	}
	
	printf("\nNo of frames:");
	scanf("%d",&f);
	
	for(i=0;i<f;i++)
	{
		F[i].in=1000;
		F[i].least=0;
	}
	int noOfPageFaults=0;
	int setPrio=1;
	for(i=0;i<p;i++)
	{
		for(j=0;j<f;j++)
		{
			if(input[i]==F[j].in)
			{
				//increment the least
				F[j].least=setPrio++;
				break;
			}
		}
		if(j>=f)
		{
			int ind=find_leastRecentOne();
			F[ind].in=input[i];
			noOfPageFaults++;
			F[ind].least=setPrio++;		
	    }
	    
	    int h;
	    for(h=0;h<f;h++)
	    {
	    	if(F[h].in==1000)
	    	{
	    		printf("_ ");
			}
			else
			{
				printf("%d ",F[h].in);
			}
		}
		printf("\n");
	}
	printf("\nNo of page Faults are %d",noOfPageFaults);
	printf("\nNo of page Repalcements are %d",noOfPageFaults-f);
}

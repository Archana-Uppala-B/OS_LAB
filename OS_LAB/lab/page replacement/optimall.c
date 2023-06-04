#include <stdio.h>
#include <stdlib.h>

int p,f;
int input[50];
struct frame{
	int in;
	int future;
};

struct frame F[10];

int find_farthest()
{
	int max=-1,index=-1,c;
	for(c=0;c<f;c++)
	{
		if(max<F[c].future)
		{
			max=F[c].future;
			index=c;
		}	
	}
	return index;
}

int main()
{
	int i,j,l,k;
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
		F[i].future=100;
	}
	int noOfPageFaults=0;
	for(i=0;i<p;i++)
	{
		for(j=0;j<f;j++)
		{
			if(input[i]==F[j].in)
			{
				//no pagefault..
				//printf("The page is not replaced...");
				break;
			}
		}
		if(j>=f)
		{
			
			for(l=0;l<f;l++)
			{
				for(k=i+1;k<p;k++)
				{
					if(F[l].in==input[k])
					{                               //storing the future values...
						F[l].future=k;
						break;
					}
				}
				if(k>=p)
				{
					F[l].future=1000;   //if the page if not at all used in the future...
				}			
			}
			int ind=find_farthest();
			F[ind].in=input[i];
			noOfPageFaults++;		
		}
		int g;
		for(g=0;g<f;g++)
		{
			if(F[g].in==1000)
			{
				printf("_ ");
			}
			else
			{
				printf("%d ",F[g].in);
			}
		}
		printf("\n");
	}
	printf("\nNo of page Faults are %d",noOfPageFaults);
	printf("\nNo of page Repalcements are %d",noOfPageFaults-f);
}

/*
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/

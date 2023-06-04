#include <stdio.h>
#include <stdlib.h>

int n,r,curr;
int seekTime=0;

int rq[20];

void sort()
{
	int i,j;
	for(i=0;i<r+3;i++)
	{
		for(j=0;j<(r+3)-i-1;j++)
		{
			if(rq[j]>rq[j+1])
			{
				int temp=rq[j];
				rq[j]=rq[j+1];
				rq[j+1]=temp;
			}
		}
	}
}

int main()
{
	int i;
	printf("Total no of tracks: ");
	scanf("%d",&n);
	
	printf("No. of requests: ");
	scanf("%d",&r);

	
	for(i=0;i<r;i++)
	{
		scanf("%d",&rq[i]);  //storing the requests;
	}
	
	printf("Enter the current disk position: ");
	scanf("%d",&curr);
	
	rq[i++]=0;
	rq[i++]=n-1;
	rq[i++]=curr;
	
	sort();
	
	//find the curr pos in the arr
	for(i=0;i<r+3;i++)
	{
		if(rq[i]==curr)
	      break;
	}
	
	int ns=r+3;
    printf("\nThe serving order of requests are:");
    printf("\n");
    int k;
    for(k=i+1;k<ns;k++)
    {
    	if(rq[k]==n-1)
    	{
    		break;
		}
    	printf("%d ",rq[k]);
	}
	seekTime+=(n-1)-curr;
	
	for(k=i-1;k>0;k--)      //not going till the end;
	{
		printf("%d ",rq[k]);
	}
	seekTime+=((n-1)-rq[i-1])+(rq[i-1]-rq[1]);
	
	printf("\n\nTotal head momements are %d",seekTime);
}

/*
82 170 43 140 24 16 190
*/

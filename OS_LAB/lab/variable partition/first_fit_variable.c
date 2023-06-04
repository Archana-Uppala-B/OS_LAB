#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process{
	int pno;
	int size;
	bool stat;
};

struct block{
	int bno;
	int size;
	bool stat;
};

struct process pro[10];
struct block blo[10];

int main()
{
	int i,j;
	int p,b;
	printf("No of blocks:");
	scanf("%d",&b);
	printf("No of processes:");
	scanf("%d",&p);
	
	printf("processes\n");
	for(i=0;i<p;i++)
	{
		scanf("%d %d",&pro[i].pno,&pro[i].size);
	}
	
	for(i=0;i<b;i++)
	{
		scanf("%d %d",&blo[i].bno,&blo[i].size);
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<b;j++)
		{
			if(pro[i].stat==false && blo[j].stat==false && pro[i].size<=blo[j].size)
			{
				printf("\n%d is mapped to %d ",pro[i].pno,blo[j].bno);
				pro[i].stat=true;
				blo[j].size-=pro[i].size;
				if(blo[j].size==0)
				{
					blo[j].stat=true;
				}
				
			}
			
		}
	}
	
	
}

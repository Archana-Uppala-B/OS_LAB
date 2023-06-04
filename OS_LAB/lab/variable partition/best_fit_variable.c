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

int p,b;

struct process pro[10];
struct block blo[10];

void sort()
{
	int i,j;
	for(i=0;i<b-1;i++)
	{
		for(j=0;j<b-i-1;j++)
		{
			if(blo[j].size>blo[j+1].size)
			{
				int temp=blo[j].size;
				blo[j].size=blo[j+1].size;
				blo[j+1].size=temp;
				
				temp=blo[j].bno;
				blo[j].bno=blo[j+1].bno;
				blo[j+1].bno=temp;	
			}
			
		}
	}
}

int main()
{
	int i,j;
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
	
	sort();
	int unallocp=0;
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
		if(pro[i].stat==false)
		{
			unallocp++;
			printf("\nP%d cannot be allocated..",pro[i].pno);
		}	
	}
	
	
	printf("\nThere is no internal fragmentation");
	int exfrag=0;
	for(i=0;i<b;i++)
	{
		if(blo[i].stat==false)
		{
			exfrag+=blo[i].size;
		}
	}
	if(unallocp!=0)
	{
		printf("\nThe external fragmentation is %d",exfrag);
	}	
}
/*
1 20
2 30
3 40
4 425
1 300
2 150
3 450
*/

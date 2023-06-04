#include <stdio.h>
#include <stdbool.h>

struct process{
	int id;
	int mem;
	int stat;
};

struct block{
	int idd;
	int size;
	bool statt;
};

int n1,n2;

struct process p[10];
struct block b[10];
int main()
{
	int i,j;
	printf("Enter the no. of processes");
	scanf("%d",&n1);
	printf("Enter the process id and memory req:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d %d",&p[i].id,&p[i].mem);
		p[i].stat=false;
	}
	
	printf("Enter the no. of block");
	scanf("%d",&n2);
	printf("Enter the block id and size :\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d %d",&b[i].idd,&b[i].size);
		b[i].statt=false;
	}
	
	int infrag=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p[i].mem<=b[j].size && p[i].stat==false && b[j].statt==false)
			{
				printf("\nP%d mapped to B%d",p[i].id,b[j].idd);
				if(b[j].size-p[i].mem>0)
				{
					infrag=infrag+(b[j].size-p[i].mem);
				}
				p[i].stat=true;
				b[j].statt=true;
			}
		}
		if(p[i].stat==false)
		{
			printf("\nmemory cannot be allocated to P%d",p[i].id);
		}
	}
	int unallp=0;
	for(i=0;i<n1;i++)
	{
		if(p[i].stat==false)
		{
			unallp=unallp+p[i].mem;
		}
	}
	
	int unallb=0;
	for(i=0;i<n2;i++)
	{
		if(b[i].statt==false)
		{
			unallb=unallb+b[i].size;
		}
	}
	
	if(unallb>=unallp)
	{
		printf("\nTotal External fragmentation is %d",unallb);
	}
	
	printf("\nInternal fragmentation is %d",infrag);	
}
/*
1 212
2 417
3 112
4 426
*/

/*
1 100
2 500
3 300
4 200
5 600
*/

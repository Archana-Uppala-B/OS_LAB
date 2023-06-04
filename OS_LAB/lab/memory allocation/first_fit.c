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
	}
	
	printf("Enter the no. of block");
	scanf("%d",&n2);
	printf("Enter the block id and size :\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d %d",&b[i].idd,&b[i].size);
	}
	
	
	for(i=0;i<n1;i++)
	{
		p[i].stat=false;
	}
	
	for(i=0;i<n2;i++)
	{
		b[i].statt=false;
	}
	
	int internal=0,external=0;
	int unalloc_count=0,un_process_mem=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p[i].mem<=b[j].size && p[i].stat==false && b[j].statt==false)
			{
				printf("\nP%d mapped to B%d",p[i].id,b[j].idd);
				internal=internal+(b[j].size-p[i].mem);
				p[i].stat=true;
				b[j].statt=true;
			}
		}
		if(p[i].stat==false)
		{
			printf("\nmemory cannot be allocated to P%d",p[i].id);
			unalloc_count++;
			un_process_mem+=p[i].mem;
		}
	}
	int un_alloc=0;
	un_alloc+=internal;
	for(i=0;i<n2;i++)
	{
		if(b[i].statt==false)
		{
			un_alloc+=b[i].size;
		}
	}
	 if(unalloc_count!=0)
	 {
	 	if(un_alloc-un_process_mem>=0)
	 	{
	 		printf("\nExternal fragmentation is %d",un_alloc);
		}
		else
	 {
	 	printf("\nNo external fragmentation");
	 }
	 }
	 
	 printf("\nInternal fragmentation is %d",internal);
	 
}

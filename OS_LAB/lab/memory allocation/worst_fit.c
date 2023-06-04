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

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(b[j].size<b[j+1].size)
			{
				swap(&b[j].idd,&b[j+1].idd);
			    swap(&b[j].size,&b[j+1].size);
			    swap(&b[j].statt,&b[j+1].statt);
				
			}
		}
	}
}

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
	
	
	int k;
	sort(n2); //sorting
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p[i].mem<=b[j].size && p[i].stat==false && b[j].statt==false)
			{
				printf("\nP%d mapped to B%d",p[i].id,b[j].idd);
				p[i].stat=true;
				b[j].statt=true;
			}
		}
		if(p[i].stat==false)
		{
			printf("\nmemory cannot be allocated to P%d",p[i].id);
		}
	}	
	

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
3 200
4 300
5 600
*/


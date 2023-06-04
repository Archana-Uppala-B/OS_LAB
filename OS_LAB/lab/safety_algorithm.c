#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct matrix{
	int a;
	int b;
	int c;
};

int main()
{
	int n;
	int i;
	printf("Enter the no of processes");
	scanf("%d",&n);
	
	struct matrix A[n],M[n],a[1],N[n];
	
	printf("\nEnter the allocation\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&A[i].a,&A[i].b,&A[i].c);
	}
	
	printf("\nEnter the Max needed\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&M[i].a,&M[i].b,&M[i].c);
	}
	
	printf("\nEnter the available:\n");
	scanf("%d %d %d",&a[0].a,&a[0].b,&a[0].c);
	
	bool finish[n];
	//need matrix
	for(i=0;i<n;i++)
	{
		N[i].a=M[i].a-A[i].a;
		N[i].b=M[i].b-A[i].b;
		N[i].c=M[i].c-A[i].c;
		finish[i]=false;
	}

    printf("One of the safe sequence is:...\n");
	int count=0;
	while(count!=n)
	{
		for(i=0;i<n;i++)
		{
			if(a[0].a>=N[i].a && a[0].b>=N[i].b && a[0].c>=N[i].c && finish[i]==false)
			{
				printf("P%d ",i);
				count++;
				finish[i]=true;
				a[0].a=a[0]+A[i].a;
				a[0].b=a[0]+A[i].b;
				a[0].c=a[0]+A[i].c;
			}
		}
		
	}
}

/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/

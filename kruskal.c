#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int a[MAX][MAX];
int parent[MAX];
int i,j,n;
int e,u,g,v;
int min_cost=0;
int EDG_no=1;
int  min_weight;



int find(int i)
{
	if(parent[i] !=i)
	{
		return find(parent[i]);
			
	}
	return i;
	
}



int Union(int i , int j)
{
	while(i !=j)
	{
		parent[j] =i;
		
		return 1;	
	}
	return 0;
	
}



int kruskal(int n)
{
	while(EDG_no <n){
		for(i=0, min_weight =1000 ; i<n ;i++)
		{
			for(j=0 ; j<n ;j++)
			{	printf("cost =%d\n",a[i][j]);
				if(a[i][j] < min_weight)
				{
					min_weight = a[i][j];
					e=u=i;
					g=v=j;
				}	
			}
		}
		u=find(u);
	    v = find(v);
	   if(Union(e ,g))
	   {
	 	printf("\n %d edge(%d %d) = %d \n",EDG_no++,e,g ,min_weight );
	 	min_cost = min_cost + min_weight;
	 		
	 }
	 a[e][g] = a[g][e] = 1000;
		
		
	}
	  printf("\nMinimum cost = %d\n", 	min_cost);
	 	
}




int main()
{
	printf("\n Enter the node \n");
	scanf("%d",&n);
	for(i=0 ; i<n ;i++)
	{
		for(j=0 ;j<n ;j++)
		{
			printf("\n Enter the cost a[%d][%d]:\n",i,j);
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0)
			{
				a[i][j] =1000;
			}
		}
	}
	
		for(i=0 ; i<n ;i++)
	{
		for(j=0 ;j<n ;j++)
		{
		
			printf("%d\t",a[i][j]);
			if(j==n-1)
			{
				printf("\n");
			}
		}
	}
	kruskal(n);
	
	
}

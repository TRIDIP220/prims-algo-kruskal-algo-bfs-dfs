#include<stdio.h>
int main()
{
	int cost[10][10],visited[10]={0};
	int i ,j,n,e_no=1 ,min, min_cost=0;
	int a ,b;
	printf("\n Enter the number of node \n");
	scanf("%d",&n);
	for(i=1 ; i<= n ;i++)
	{
		for(j=1 ; j<=n ; j++)
		{
			
			printf("\n Enter the cost \n");
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0)
			{
				cost[i][j]= 1000;
			}
		}
	}
	for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=n ;j++)
		{
			printf("%d\t",cost[i][j]);
			if(j == n)
			
			{
				printf("\n");
			}
		}
}
visited[1]= 1;
while(e_no < n)
{
	min=1000;
	for(i=1 ; i<=n ;i++)
	{
		for(j=1 ; j<=n ;j++)
		{
			
			if(cost[i][j] < min)
			{
				if(visited[i] != 0)
				{
					min = cost[i][j];
					a= i;
					b=j;
					
				}
				
				
			}
		}
	}
	if(visited[b] == 0)
	{
		printf("%d to %d cost = %d\n" , a , b , min);
		min_cost = min_cost +min;
		e_no++;
		
	}
	visited[b] =1;
	cost[a][b]= cost[b][a] = 1000;
	
	
}
printf("minimum cost = %d", min_cost);
		
}

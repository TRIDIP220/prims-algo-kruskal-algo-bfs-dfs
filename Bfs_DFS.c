#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 
struct node
{
    int size;
    int f;
    int r;
    int top;
    int* arr;
};
 
int isEmpty_Q(struct node *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isEmpty_S(struct node *p)
{

	if(p->top == -1)
	{
		return 1;	
	}
	else{
	
	return 0;
}
	
}
 
int isFull_Q(struct node *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isFull_S(	struct node *p)
{

	if(p->top == p->size -1)
	{
		return 1;	
	}
	else{
	
	return 0;
	
}
	
}

 
void enqueue(struct node *q, int val){
    if(isFull_Q(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
       
    }
}
 
int dequeue(struct node *p){
	int a = -1;
    if(isEmpty_Q(p)){
        printf("This Queue is empty\n");
    }
    else{
        p->f++;
        a = p->arr[p->f]; 
    }
    return a;
   
}

int push(struct node *p , int val)
{
	if(isFull_S(p))
	{
		printf("\n Node is Full \n");
	}
	else{
		
		p->top++;
		p->arr[p->top] = val;
	
		
		
	}
	
}

int pop(struct node *p)
{
	int val;
	if(isEmpty_S(p))
	{
		printf("\n Node is Empty \n");
		return -1;
	}
	else{
		
		val= p->arr[p->top];
		p->top = p->top - 1;
		printf("%d",val);
		return val;
		
	}
	
}




int BFS(int start)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int*) malloc(q->size*sizeof(int));
	 int i ,j,n;
	 printf("\n Enter the range \n");
	 scanf("%d",&n);
    
    int visit[MAX], adj[MAX][MAX];
    for(i=0 ; i<n ; i++)
    {
    printf(" visit[%d]=",i);
    scanf("%d",&visit[i]);
	}
	for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%d", &adj[i][j]);
      }
   }
   
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("%d ", adj[i][j]);
         if(j==n-1){
            printf("\n");
         }
      }
   } 
      	
  for(i=0 ; i< n ; i++)
  {
  	if(i == start)
  	{
    visit[start] = 1;
    
    } 
}
  enqueue(q , start);
  
  while(!isEmpty_Q(q))
  {
  	int node = dequeue(q);
  	printf("%d",node);
  	for(j=0 ; j<n ; j++)
  	{
  		
  		if((adj[node][j])==1 && visit[j] == 0)
  		{
  			visit[j] =1;
  			enqueue(q,j);
  		
		  }

	  }
}
	
}

int Dfs(int i)
{
		
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->top = -1;
	p->size =100;
	p->arr  = (int *)malloc(sizeof(int) *p->size);
	int j,k;
	int l,n;
	int visit[MAX];
	int a[MAX][MAX];
	printf("\n Enter the range \n");
	scanf("%d",&n);
	for(l =0 ; l< n ;l++)
	{
		
	 printf("\n Initialize the visit[%d]=",l); 
	 scanf("%d",&visit[l]);
	
	}
	for(l =0 ; l<n ;l++)
	{
		for(k=0 ; k<n ; k++)
		{
			printf("\n Enter the adjacent Matrix according to your graph a[%d][%d]=",l,k);//
			scanf("%d",&a[l][k]);
		}
	}
	for(l=0 ; l<n ;l++){
		for(k=0 ; k<n ;k++)
		{
			printf("%d",a[l][k]);
			if(k == n-1)
			{
				printf("\n");
			}
		}
	}
	
	for(l =0 ; l< n ;l++)
	{
		if(l == i)
		{
			visit[l]= 1;
		}
	}
	
	push(p,i);
	 while(!isEmpty_S(p))
    {
       k=pop(p);
	for(j=0 ; j<7 ; j++)
	{
		if(a[k][j] == 1 && visit[j]==0)
		{
			visit[j] = 1;
			push(p,j);	
		
				
		}
	
	}
}
		
}




 
int main(){
    
   
int n,choice;

while(1)
{
	printf("\n press 1 for BFS , press 2 for DFS , press 3 for exit(0):");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n Enter the starting node \n");
			scanf("%d",&n);
			BFS(n);
			break;
		case 2:
			printf("\n Enter the starting node \n");
			scanf("%d",&n);
			Dfs(n);
			break;
		case 3:
			exit(0);
				
	}
	
}
     
}


#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};


struct node *creat(int val)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data = val;
	p->left =NULL;
	p->right =NULL;
	return p;
	
}


int insert(struct node *root , int key)
{
	struct node *p=NULL;
	
	while(root !=NULL)
	{
		p=root;
		if(key == root->data)
		{
			printf("\n DUPLICATE IS NOT ALLOW \n");
			return ;
			
		}
			else if(key > root->data)
		{
			
		    root = root->right;

		
		}
		else{
			
			root = root->left;
	
		
			
		}	
		
	}
	struct node *n;
	n = creat(key);
	if(key >p->data)
	{
		p->right = n;
		
	}
	else
	{
		p->left = n;
		
	}
}

void preOrder(struct  node* root){
    if(root!=NULL)
	{
        printf("%d ", root->data);
        
        preOrder(root->left);
        
        preOrder(root->right);
    }
}


void postOrder(struct  node* root){
    if(root!=NULL)
	{
        postOrder(root->left);
        
        postOrder(root->right);
        
        printf("%d ", root->data);
    }
}


void inOrder(struct  node* root){
    if(root!=NULL)
	{
        inOrder(root->left);
        
        printf("%d ", root->data);
        
        inOrder(root->right);
    }
}

struct node *predecessor(struct node *root)
{
	root = root->left;
	while(root->right != NULL)
	{
		root=root->right;
			
	}
  printf("predecessor=%d",root->data);
	
		
}

struct node *successor(struct node *root)
{
	root = root->right;
	while(root->left != NULL)
	{
		root=root->left;
			
	}
  printf("predecessor=%d",root->data);
	
		
}



int main ()
{
	printf("\n------------- CREAT OPERATION---------------- \n");
	int p,choice,n,j;
	
	printf("\n Enter the root value \n");
	
	scanf("%d",&p);
	
	struct node *root=creat(p);
	
	printf("\n ROOT VALUE IS = %d \n",root->data);
	
	printf("\nEnter a number for the second node purpose\n");
	
	scanf("%d",&n);
	
	if(n < root->data)
	 {
	 struct node *p1=creat(n);
	 root->left = p1;	
	}
	
	else{
		struct node *p1=creat(n);
		root->right = p1;	
	}


         /*  5
           / \
          3   6
        / \
       1   4  */


	while(1){
	  printf("\n press 1=INSERT() , 2=preorder() , 3=postorder() , 4= inorder() ,5=predecessor(),6=successor() ,7= exit(0) \n");//50, 70, 60, 20, 90, 10, 40, 100
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("\nEnter the value for insert purpose \n");
	  		scanf("%d",&j);
	  		insert(root,j);
	  		break;
	  	case 2:
	  		printf("\nPREORDER SEQUENCE = ");
	  		preOrder(root);
	  		break;
	  	case 3:
	  		printf("\nPOSTORDER SEQUENCE = ");
	  		postOrder(root);
	  		break;
	  	case 4:
	  		printf("\nINORDER SEQUENCE = ");
	  		inOrder(root);
	  		break;
	  	case 5:
	  		predecessor(root);
	  		break;
	  	case 6:
	  		successor(root);
	  		break;
	  		
	  	case 7:
	  		exit(0);
	  		
	  }	
	}
	


}




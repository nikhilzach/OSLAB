#include<stdio.h>
#include <stdlib.h>
int np=0,i=0,psize[100];
struct node
{
	int pno,bno,remsize,bsize,psizevar;
	struct node *next;
}*start,*ptr,*newnode;


void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
		ptr->psizevar=ptr->bsize-ptr->remsize;
		printf("Process no   processsize    Block no    remaining space\n");
		printf("    %d           %d              %d          %d\n",ptr->pno,ptr->psizevar,ptr->bno,ptr->remsize);
		ptr=ptr->next;
	}
}

void firstfit()
{
	i=0;
			
	for(i=1;i<=np;i++)
		{
				ptr=start;
				printf("%d\n",i);
				while(ptr!=NULL)
			{
			
				if(psize[i]<ptr->bsize)
				{
						printf("%d  %d\n",psize[i],ptr->bsize);
					ptr->remsize = ptr->bsize-psize[i];
					ptr->pno=i;
					ptr=ptr->next;
					break;
				}
			
			else
			
			ptr=ptr->next;
			}
		}
			
		
}

void main()
{
	int nb;
	printf("Enter no of processes:  ");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter processsize of %d : ",i+1);
		scanf("%d",&psize[i]);
	}
	printf("enter no of blocks : ");
	scanf("%d",&nb);
	for(i=0;i<nb;i++)
	{
		if(i==0)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			start=newnode;
			newnode->next=NULL;
		}
		else
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
		}
		
		printf("Enter Block Size %d: ",i+1);
		newnode->bno=i+1;
		scanf("%d",&newnode->bsize);

	}
	i=0;
			firstfit();
			display();
}

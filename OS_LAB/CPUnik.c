#include<stdio.h>

int np,i,j;
struct process
{
	int at,bt,wt,tt,pid;
}readyq[100],temp;

void display()
{
	printf("PID\tAT\tBT\tTT\tWT\n");
	for(i=0;i<np;i++)
	{
		
		printf("%d\t%d\t%d\t%d\t%d\n",readyq[i].pid,readyq[i].at,readyq[i].bt,readyq[i].tt,readyq[i].wt);

		
	}
}

void FCFS()
{
	int time=0;
for(i=0;i<np;i++)
readyq[i].tt=0;
	for(i=0;i<np;i++)
	{
		
		for(j=0;j<np-i-1;j++)
		{
			if( readyq[j].at>readyq[j+1].at)
			{
				printf("HEYY\n");
				temp = readyq[j];
				readyq[j] = readyq[j+1];
				readyq[j+1] = temp; 
			}
		}
		time = time + readyq[i].bt ;
		readyq[i].tt=time- readyq[i].at;
		if(i==0)
		{ readyq[i].wt==0;
		  readyq[i+1].wt=time-readyq[i+1].at;}
		else
		readyq[i+1].wt = time-readyq[i+1].at;
	}
	
}

void main()
{
	int ch;
	printf("Enter no of process ");
	scanf("%d",&np);
	printf("AT   BT");
	for(i=0;i<np;i++)
	{
		scanf("%d  %d",&readyq[i].at,&readyq[i].bt);
				readyq[i].pid=i;
	}
	printf("Select type of scheduling:");
	printf("1.FCFS\n2.SJF\n3.Priority\n4.RoundRobin");
	scanf("%d",&ch);
	if(ch==1)
	FCFS();
	if(ch==2);
	//SJF();
	if(ch==3);
//	priority();
	if(ch==4);
	//roundrobin();
	display();
}

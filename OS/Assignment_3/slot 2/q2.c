#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,seek=0,max,head,move,q[100];
	printf("\n Enter queue size:");
	scanf("%d",&n);
	printf("\n Enter queue elements:");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position:");
	scanf("%d",&head);
	printf("\n Enter max disk size:");
	scanf("%d",&max);
	printf("\n Enter the head movemnet direction 1 for high and 0 foe low:");
	scanf("%d",&move);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(q[j]>q[j+1])
			{
				int temp;
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
	
	int index;
	for(i=0;i<n;i++)
	{
		if(head<q[i])
		{
			index=i;
			break;
		}
	}
	
	printf("\n Sequence of head movement:");
	if(move==1)
	{
		printf("%d\t",head);
		for(i=index;i<n;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(max-q[i-1]-1);
		seek+=abs(max-1-0);
		printf("%d\t",max-1);
		head=0;
		printf("%d\t",head);
		for(i=0;i<index;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	else
	{
		printf("%d\t",head);
		for(i=index-1;i>=0;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(q[i+1]-0);
		seek+=abs(max-1-0);
		head=max-1;
		printf("%d\t",head);
		for(i=n-1;i>=index;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	printf("\n\n Total head movements are %d",seek);
	return 0;
}

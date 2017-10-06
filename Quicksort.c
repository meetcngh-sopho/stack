#include<stdio.h>
 int Lo[50];
 int Up[50];
 static int top=-1;
static int c;
static int d;
int RL(int arr[],int piv)
{
	int i,temp;
	for(i=c;i>d;i--)
	{
		if(piv>arr[i])
		{
		    temp=arr[i];
		    arr[i]=piv;
		    arr[d]=temp;
			c=d;
			d=i;
			return 1;
		}
	}
	return 2;
}
int LR(int arr[],int piv)
{
	int i,temp;
	for(i=c+1;i<d;i++)
	{
	    
		if(piv<arr[i])
		{
		 temp=arr[i];
		    arr[i]=piv;
		    arr[d]=temp;

			c=d;
			d=i;
			return 1;
		}
	}
	return 2;
}
void qsort(int arr[],int size,int firstindex,int lastindex)
{
	d=firstindex;
	c=lastindex;
	int piv=arr[firstindex];
	int count=0,a;
	while(1)
	{
		if(count==0)
		{
			a=RL(arr,piv);
			count++;

		}
			else if(count==1)
			{
				a=LR(arr,piv);
				count=0;

			}
			else{
				//do nothing
			}
			if(a!=1)
			{
				break;

			}

	}
	if(d+1==lastindex||d==lastindex)
	{
		//right part is sorted
		if(c+1==d)
			return;

		top++;
		Lo[top]=firstindex;
		Up[top]=d-1;
		qsort(arr,8,Lo[top],Up[top]);
		top--;
	}
	else if(d==firstindex||d-1==firstindex)
	{
		if(c+1==d)
			return ;
		//left part is sorted
		top++;

		Lo[top]=d+1;
		Up[top]=lastindex;
		qsort(arr,8,Lo[top],Up[top]);
		top--;

	}
	else
	{
		top++;
		Lo[top]=firstindex;
		Up[top]=d-1;
		top++;
		Lo[top]=d+1;
		Up[top]=lastindex;
		qsort(arr,8,Lo[top],Up[top]);
		top--;
		qsort(arr,8,Lo[top],Up[top]);
		top--;

	}

}
int main()
{
	printf("Enter how many element of array");
	printf("\n");
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	top++;
	Lo[top]=0;
	Up[top]=n-1;
	qsort(arr,n,Lo[top],Up[top]);
	top--;
	
	for(i=0;i<n;i++)
		printf("%d		",arr[i]);
	printf("\n");

return 0;
}

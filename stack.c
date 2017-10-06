#include<stdio.h>
struct node
{
    int lower;
int upper;
struct node *next;

};
int *r=NULL;
typedef struct node n;
n *pushstack(int a,int b)
{
    n *start=(struct node *)malloc(sizeof(n));
    start->lower=a;
    start->upper=b;
    start->next=r;
    r=start;
    return r;
}
void display(int a[],int size)
{
    int i;
    for( i=0;i<size;i++)
        printf("%d ",a[i]);
    return;
}
int poplower(n *start)
{


    return start->lower;
}
n *displaystack(n *start)
{
    n *p=start;
    while(p!=NULL)
    {
        printf("%d %d",p->lower,p->upper);
        p=p->next;
    }
    return start;
}
int popupper(n *start)
{
    return (start->upper);
}
n *pop(n *start)
{
    start=start->next;
    return start;
}
void Quicksort(int a[],int size,int *L,int *R)
{
    int count=0,temp;
    int P=a[0];
while(1)
{
    if(count==0)
    {
        if(P>*R)
        {
            temp=*R;
            *R=P;
            *L=temp;
            count++;
            L++;
        }
        else
        {
            R--;
        }
    }
    if(count==1)
    {
        if(P<*L)
        {
            temp=*L;
            *L=P;
            *R=temp;
            count=0;
            R--;

        }
        else
        {
            L++;
        }

    }
    if(*L==P&&*R==P)
    {

        break;
    }

}
}
int main()
{
int a[8],i;
for(i=0;i<8;i++)
   scanf("%d",&a[i]);


n *start=pushstack(0,7);

Quicksort(a,8,&a[poplower(start)],&a[popupper(start)]);

start=pop(start);
displaystack(start);
return 0;
}

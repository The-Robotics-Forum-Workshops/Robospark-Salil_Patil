#include<stdio.h>
#include<conio.h>

int isempty();
int isfull();
void insert(int elem, int p);
int getHigh(); 
int deleteHigh(); 
void display();



struct pqueue
{
    int elem;
    int priority;
    
};
typedef struct pqueue pqueue;
pqueue pq[20];
int rear = -1;

int main()
{
    int size,data, p,sum;
    printf("Enter the number of ropes: ");
    scanf("%d",&size);

    printf("Enter the size of ropes: \n");

    for(int i=0; i<size; i++)
    {   
        scanf("%d",&data);
        insert(data,data);
    }
    int a,b,cost = 0;
    while(rear != 0)
    {   
        a = getHigh();
        deleteHigh();

        b = getHigh();
        deleteHigh();

        
        sum = a+b;
        insert(sum,sum);
        cost = cost + sum;

    }
    printf("cost: %d", cost);
    

        
}


int isempty()
{
    if (rear == -1)
    return 1;
    else return 0;
}

int isfull()
{
    if(rear==4)
    return 1;
    else
    return 0;   
}
void insert(int ele, int p)
{
    rear = rear+1;
    pq[rear].elem = ele;
    pq[rear].priority = p;
}
int getHigh()
{
    int i, p=-1;
    p = pq[0].priority;
    if(!isempty())
    {
        
        for(i=0; i<=rear; i++)
        {
            if(pq[i].priority<p)
            {
                p = pq[i].priority;

            }
        }
    }
    return p;
}
int deleteHigh()
{
    int i,j,p,ele;
    p=getHigh();
    for(i=0; i<=rear;i++)
    {
        if(pq[i].priority == p)
        {
            ele = pq[i].elem;
            break;
        }
    }
    if(i<rear)
    {
        for(j=i;j<rear;j++)
        {
            pq[j].elem= pq[j+1].elem;
            pq[j].priority = pq[j+1].priority;
        }
    }
    rear = rear-1;
   return ele; 
}

void display()
{
    int i;
    printf("\n Priority queue:\n ");
    for(i=0;i<rear;i++)
    {
        printf("ele = %d, priority = %d\n", pq[i].elem, pq[i].priority);
    }
}
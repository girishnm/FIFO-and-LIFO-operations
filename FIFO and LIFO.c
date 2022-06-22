#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct dequeue

{

int data[MAX];

int rear,front;

}dequeue;


void initialize(dequeue *p);

int empty(dequeue *p);

int full(dequeue *p);

void enqueueR(dequeue *p,int x);


int dequeueF(dequeue *p);

int dequeueR(dequeue *p);

void print(dequeue *p);
void avg(dequeue *p, dequeue *q,int n);
void main()

{


int i,x,d[10],n,op,del;

dequeue q,qtt;

initialize(&q);
initialize(&qtt);

do

{

printf("\n1.Create\n2.Delete LIFO");

printf("\n3.Delete FIFO\n4.Print\n5:Get Average \n6.Exit\nEnter your choice:\n");

scanf("%d",&op);

switch(op)

{

case 1: printf("\nEnter number of elements:\n");

scanf("%d",&n);

initialize(&q);
initialize(&qtt);


printf("\nEnter the number of tokens separated by comma\n");

for(i=0;i<n;i++)

{

scanf("%d,",&x);

if(full(&qtt))

{

printf("\nQueue is full!!");

exit(0);

}

enqueueR(&qtt,x);

}




printf("\nEnter the corresponding price separated by comma\n");

for(i=0;i<n;i++)

{

scanf("%d,",&x);

if(full(&q))

{

printf("\nQueue is full!!");

exit(0);

}

enqueueR(&q,x);

}

break;





case 2: if(empty(&q))

{

printf("\nQueue is empty!!");

exit(0);

}
printf("Please enter how many elements you want to delete\n");
scanf("%d",&del);
for (i=0;i<del;i++){
    d[i]=dequeueR(&q);
    d[i]=dequeueR(&qtt);
    n--;
}
// printf("\nElement deleted are\n");
// for (i=0;i<del;i++)
//     printf("%d," d[i]);
break;

case 3: if(empty(&q))

{

printf("\nQueue is empty!!");

exit(0);

}
printf("Please enter how many elements you want to delete\n");
scanf("%d",&del);
for (i=0;i<del;i++)
{
    d[i]=dequeueF(&q);
d[i]=dequeueF(&qtt);
n--;

}
//printf("\nElement deleted is %d\n",x);

break;

case 4: print(&q);

break;
case 5: avg(&q,&qtt,n);

default: break;

}

}while(op!=7);


}

void initialize(dequeue *P)

{

P->rear=-1;

P->front=-1;

}

int empty(dequeue *P)

{

if(P->rear==-1)

return(1);

return(0);

}

int full(dequeue *P)

{

if((P->rear+1)%MAX==P->front)

return(1);

return(0);

}

void enqueueR(dequeue *P,int x)

{

if(empty(P))

{

P->rear=0;

P->front=0;

P->data[0]=x;

}

else

{

P->rear=(P->rear+1)%MAX;

P->data[P->rear]=x;

}

}


int dequeueF(dequeue *P)

{

int x;

x=P->data[P->front];

if(P->rear==P->front) //delete the last element

initialize(P);

else

P->front=(P->front+1)%MAX;


return(x);

} 

int dequeueR(dequeue *P)

{

int x;

x=P->data[P->rear];

if(P->rear==P->front)

initialize(P);

else

P->rear=(P->rear-1+MAX)%MAX;

return(x);

}

void print(dequeue *P)

{

if(empty(P))

{

printf("\nQueue is empty!!");

exit(0);

}

int i;

i=P->front;

while(i!=P->rear)

{

printf(" %d",P->data[i]);

i=(i+1)%MAX;

}

printf(" %d ",P->data[P->rear]);
}

void avg(dequeue *P,dequeue *Q, int n)
{
float a=0;
if(empty(P))

{

printf("\nQueue is empty!!");

exit(0);

}

int i,j;

i=P->front;
j=Q->front;
while(i!=P->rear&&j!=Q->rear)

{

a=a+(P->data[i]*Q->data[i]);

i=(i+1)%MAX;

}
a=a+(P->data[P->rear]*Q->data[Q->rear]);
printf(" %f ",a/n);
a=0;
}

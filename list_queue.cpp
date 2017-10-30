#include<iostream>
#include<stdlib.h>
using namespace std;
struct ListQueue
{
    int data;
    struct ListQueue* next;
};
struct Queue
{
  struct ListQueue *Front,*rear;
};
struct Queue* create (long int size)
{
    struct Queue*q=(struct Queue*)malloc(sizeof(struct Queue));
    q->Front=NULL;
    q->rear=NULL;
    return q;
};
struct ListQueue* newNode(int val)
{
    struct ListQueue* lq=(struct ListQueue*)malloc(sizeof(struct ListQueue));
    lq->data=val;
    lq->next=NULL;
    return lq;
};
void enqueue(struct Queue *obj,int val)
{
    struct ListQueue* temp=newNode(val);
    if(obj->rear==NULL)
    {
        obj->Front=obj->rear=temp;
        return;
    }
        obj->rear->next=temp;
        obj->rear=temp;
}
struct ListQueue* dequeue(struct Queue *obj)
{
  if(obj->Front==NULL)
  {
      return NULL;
  }
  struct ListQueue *temp1=obj->Front;
  obj->Front=obj->Front->next;
  if(obj->Front==NULL)
  {
      obj->rear=NULL;
  }
      return temp1;
}
int main()
{
    struct Queue* q=create(1000);
    enqueue(q,10);
     enqueue(q,20);
      enqueue(q,30);
      struct ListQueue *n=dequeue(q);
      cout<<n->data;
      struct ListQueue *p=dequeue(q);
      cout<<p->data;
      return 0;
}

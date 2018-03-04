#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
int data;
struct node*next;
};
void Insert(struct node**h,int value)
{
  if(*h==NULL)
  {
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    n->next=*h;
    *h=n;
  }
  else
  {
    struct node*curr=*h;
    while(curr->next!=NULL)
    {
      curr=curr->next;
    }
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    curr->next=n;
    n->next=NULL;
  }
}
void Insert_pos(struct node**h,int pos,int value)
{
    int i=1;
    struct node*loc=*h;
    while(i<pos-1 && loc!=NULL)
    {
        i++;
        loc=loc->next;
    }
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    n->next=loc->next;
    loc->next=n;
}
void Delete(struct node**h)
{
    if(*h==NULL)
    {
        struct node*temp=*h;
        if(temp!=NULL)
        {
            *h=temp->next;
            free(temp);
       }
    }
    struct node*loc=*h;
    while(loc!=NULL && loc->next!=NULL)
    {
        if(loc->next->next!=NULL)
        {
            loc=loc->next;
        }
        struct node*temp1=loc->next;
        loc->next=NULL;
        free(temp1);
    }
}
void reverse_list(struct node**h)
{
    struct node*prev=NULL;
    struct node*curr=*h;
    struct node*next_;
    while(curr!=NULL)
    {
        next_=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_;
    }
    *h=prev;
}
void middle_ele(struct node**h)
{
    struct node*fast=*h;
    struct node*slow=*h;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"mid: "<<slow->data;
}
struct node* remove_redundancy(struct node*h)
{
   struct node*p1,*p2,*dup;
   p1=h;
   while(p1!=NULL && p1->next!=NULL)
   {
       p2=p1;
       while(p2->next!=NULL)
       {
           if(p1->data==p2->next->data)
           {
               dup=p2->next;
               p2->next=p2->next->next;
               free(dup);
           }
           p2=p2->next;
       }
       p1=p1->next;
   }
   return h;
}
struct node* Merge(struct node*h,struct node*t)
{
    struct node*result=NULL;
    if(t==NULL)
    {
        return h;
    }
    if(h==NULL)
    {
        return t;
    }
    else
    {
        if(h->data<t->data)
        {
            result=h;
            result->next=Merge(h->next,t);
        }
        if(h->data>t->data)
        {
            result=t;
            result->next=Merge(h,t->next);
        }
    }
    return result;
}
void reverse_pat_node(struct node*h,int v1,int v2)
{
    if(v1==v2)
    {
        return;
    }
    else
    {
        struct node*prev=NULL;
        struct node*curr=*h;
        while(curr && curr->data!=v1)
        {
            prev=curr;
            curr=curr->next;
        }
         struct node*prev1=NULL;
        struct node*curr1=*h;
        while(curr1 && curr1->data!=v2)
        {
            prev1=curr1;
            curr1=curr1->next;
        }
        if(curr==NULL || curr1==NULL)
        {
            return;
        }
        if(prev!=NULL)
        {
            prev->next=curr1;
        }
        else
        {
            *h=curr1;
        }
         if(prev1!=NULL)
        {
            prev1->next=curr;
        }
        else
        {
            *h=curr;
        }
        struct node*temp;
        temp=curr1->next;
        curr1->next=curr->next;
        curr->next=temp;
    }
}
void intersection_point(struct node*h,strcut node*t)
{
    struct node*curr=h;
    struct node*loc=t;
    while(curr!=NULL)
    {
        Count++;
        curr=curr->next;
    }
    while(loc!=NULL)
    {
        Count1++;
        loc=loc->next;
    }
    if(Count>Count1)
    {
        d=Count-Count1;
        struct node*new_curr=h;
        struct node*new_curr1=t;
        for(int i=0;i<d;i++)
        {
            if(new_curr==NULL)
            {
                return -1;
            }
            new_curr=new_curr->next;
        }
        while(new_curr!=NULL && new_curr1!=NULL)
        {
            if(new_curr==new_curr1)
             {
               printf("%d",new_curr->data);
             }
            new_curr=new_curr->next;
            new_curr1=new_curr1->next;
       }
    }
}
void swap_nodes(struct node*h)
{
    struct node*curr=h;
    if(curr==NULL || curr->next==NULL)
    {
        return;
    }
    struct node*temp=h->next;
    struct node*temp1=h->next->next;
    h->next->next=h;
    h->next=swap_nodes(temp);
    return temp;
}
void display(struct node*h)
{
while(h)
{
cout<<h->data<<" ";
h=h->next;
}
}
int main()
{
struct node*q=NULL;
struct node*res;
srcut node*result=NULL;
Insert(&q,10);
Insert(&q,20);
Insert(&q,30);
Insert(&q,40);
Insert(&q,50);
Insert(&q,60);
Insert_pos(&q,4,70);
display(q);
//Delete(&q);
reverse_pat_node(q,30,60);
swap_nodes(q);
reverse_list(&q);
cout<<"reversed: ";
display(q);
middle_ele(&q);
res=remove_redundancy(q);
display(res);
///Union();
///Intersection();
result=Merge(q,q1);
Intersection_point(q,q1);
return 0;
}

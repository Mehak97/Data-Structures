#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Stack1
{
    int top;
    int *arr;
    int MAXSIZE;
}st;
st* create(long int size)
{
    st*n_st=(st*)malloc(sizeof(st));
    n_st->top=-1;
    n_st->MAXSIZE=size;
    n_st->arr=(int*)malloc(sizeof(n_st->MAXSIZE)*sizeof(int));
    return n_st;
}
int isEmpty(st*obj)
{
    if(obj->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(st*obj)
{
    if(!isEmpty(obj))
    {
        int data;
        data=obj->arr[obj->top];
        obj->top--;
        return data;
    }
    else
        {
            return 0;
        }
}
void insert_value(st*obj,int temp)
{
    if(isEmpty(obj))
    {
        push(obj,temp);
    }
    else
    {
       int a=obj->arr[obj->top];
       pop(obj);
       insert_value(obj,temp);
       push(obj,a);
    }
}
void reverse_stack(st*obj)
{
  int temp=pop(obj);
  reverse_stack(obj);
  insert_val(obj,temp);
}
int isFull(st*obj)
{
    if(obj->top==obj->MAXSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(st*obj,int val)
{
    if(!isFull(obj))
    {
        obj->top++;
        obj->arr[obj->top]=val;
    }
}
void print(st*obj)
{
    while(obj->top>=0)
    {
        cout<<obj->arr[obj->top];
        obj->top--;
    }
}
int main()
{
struct Stack1 *nn=create(100000);
push(nn,10);
push(nn,20);
push(nn,30);
push(nn,40);
push(nn,50);
reverse_stack(nn);
print(nn);
}

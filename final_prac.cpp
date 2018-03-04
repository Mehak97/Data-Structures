#include<iostream>
//#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct tree
{
int data;
struct tree*right;
struct tree*left;
};
struct tree*Insert(struct tree*root,int value)
{
    if(root==NULL)
    {
       struct tree*n=(struct tree*)malloc(sizeof(struct tree));
       n->data=value;
       n->left=NULL;
       n->right=NULL;
       return n;
    }
   else
    {
       if(value<root->data)
       {
           root->left=Insert(root->left,value);
       }
       if(value>root->data)
       {
           root->right=Insert(root->right,value);
       }
       return root;
    }
}
int height(struct tree*r)
{
      if(r==NULL)
    {
        return 0;
    }
    else
    {
       int l=height(r->left);
       int  ri=height(r->right);
       /*if(l>ri)
        {
           return l+1;
        }
        else
         {
           return ri+1;
        }*/
        return 1+max(l,ri);
    }
}
int FIND_MAX(struct tree*root)
{
    if(root->right==NULL)
    {
      return root->data;
    }
    FIND_MAX(root->right);
}
struct tree* Delete(struct tree*root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(value<root->data)
    {
        root->left=Delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=Delete(root->right,value);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        if(root->left==NULL)
        {
            struct tree*temp=root->right;
            free(root);
            root=NULL;
            return temp;
        }
        if(root->right==NULL)
        {
            struct tree*temp=root->left;
            free(root);
            root=NULL;
            return temp;
        }
        else
        {
            int x=FIND_MAX(root->left);
            root->data=x;
            root->left=Delete(root->left,x);
        }
    }
}
int least_ances(struct tree*root,int value1,int value2)
{
        if(value1<root->data && value2>root->data)
        {
            return root->data;
        }
    else
    {
        if(value1<root->data && value2<root->data)
        {
            root=root->left;
            least_ances(root,value1,value2);
        }
        if(value1>root->data && value2>root->data)
        {
            root=root->right;
            least_ances(root,value1,value2);
        }
    }
}
int max(int a,int b)
{
   return (a>b)?a:b;
}
int Diameter(struct tree*root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
       int ldia=Diameter(root->left);
       int rdia=Diameter(root->right);
       return max(lheight+rheight+1,max(ldia,rdia));
    }
}
void left_view(struct tree*root)
{
    if(root)
    {
        if(root->left)
        {
            cout<<root->data<<" ";
            left_view(root->left);
        }
       else if(root->right)
        {
            cout<<root->data<<" ";
            left_view(root->right);
        }
    }
}
void right_view(struct tree*root)
{
    if(root)
    {
        if(root->right)
        {
            cout<<root->data<<" ";
            right_view(root->right);
        }
       else if(root->left)
        {
            cout<<root->data<<" ";
            right_view(root->left);
        }
    }
}
void leaf(struct tree*root)
{
    if(root)
    {
        leaf(root->left);
        if(root->left==NULL && root->right==NULL)
        {
            cout<<root->data<<" ";
        }
        leaf(root->right);
    }
}
void circumference_tree(struct tree*root)
{
    if(root)
    {
        cout<<root->data<<" ";
        left_view(root->left);
        leaf(root->left);
        leaf(root->right);
        right_view(root->right);
    }
}
void display(struct tree*root)
{
    if(root==NULL)
    {
        return;
    }
  display(root->left);
  cout<<root->data<<" ";
  display(root->right);
}
int main()
{
struct tree*root=NULL;
root=Insert(root,10);
root=Insert(root,12);
root=Insert(root,8);
root=Insert(root,5);
root=Insert(root,15);
root=Insert(root,2);
root=Insert(root,7);
root=Insert(root,9);
root=Insert(root,3);
root=Insert(root,4);
display(root);
int h=height(root);
cout<<endl<<"height is: "<<h<<" ";
Delete(root,15);
cout<<endl<<"after dletn ";
display(root);
int ances=least_ances(root,2,8);
cout<<"ancestor: "<<ances<<endl;
int dia=Diameter(root);
cout<<"diameter:" <<dia<<endl;
///top_view(root);
///bottom_view(root);
circumference_tree(root);
return 0;
}

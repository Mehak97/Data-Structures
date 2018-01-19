#include<iostream>
using namespace std;
int cows,stalls;
int arrange(int pos[],int max_diff,int cows,int stalls)
{
  int a=pos[0],Count=0;
   for(int i=1;i<stalls;i++)
   {
       if(pos[i]-a>=max_diff)
       {
           Count++;
           a=pos[i];
       }
   }
   if(Count==cows)
   {
      return 1;
   }
   return 0;
}
int dis(int pos[],int stalls)
{
    int last,first,max_diff,val=-1;
    last=pos[stalls-1];
    first=0;
   while(last>first)
   {
        max_diff=first+(last-first)/2;
             if(arrange(pos,max_diff,cows,stalls)==1)
               {
                   if(max_diff>val)
                   {
                       val=max_diff;
                   }
                    first=max_diff+1;
               }
            else
               {
                     last=max_diff;
               }
   }
   return val;
}
void Sort(int pos[],int stalls)
{
    for(int i=0;i<stalls;i++)
    {
       for(int j=1;j<stalls;j++)
       {
           int temp;
           if(pos[i]>pos[j])
           {
               temp=pos[i];
               pos[i]=pos[j];
               pos[j]=temp;
           }
       }
    }
}
int main()
{
    int test_case,pos[100];
    cout<<"no. of test cases ";
    cin>>test_case;
    cout<<"no. of stalls ";
    cin>>stalls;
    cout<<"no.of cows ";
    cin>>cows;
    cout<<"entr position ";
for(int i=0;i<stalls;i++)
{
cin>>pos[i];
}
Sort(pos,stalls);
int d=dis(pos,stalls);
cout<<"distance "<<d;
return 0;
}

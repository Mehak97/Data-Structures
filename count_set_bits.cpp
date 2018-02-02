#include<iostream>
using namespace std;
int numSetBits(unsigned int A) {
    int count=0;
    while(A)
    {
        count+=A&1;
        A=A>>1;
    }
    return count;
}
int main()
{
int A;
cin>>A;
int ans=numSetBits(A);
cout<<ans;
}

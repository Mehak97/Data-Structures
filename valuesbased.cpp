#include<iostream>
using namespace std;
int main()
{
    int num;
cin>>num;
cout<<((num>>31)|!(!num));//return +1 if num is +ve/-ve, if num is zero return 0
return 0;
}

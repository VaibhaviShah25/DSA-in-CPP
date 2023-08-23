#include<iostream>
using namespace std;
int sum(int n,int c)
{

    if(n==0)
        return 0
    c = n+sum(n%10);
    cout<<c;
}

int main()
{
    int n,c;
    sum(376)
return 0;
}

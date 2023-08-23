//Program to sort an array in ascending order
#include<iostream>
using namespace std;
int main()
{
    int i,j,n,temp;
    cout<<"Enter how many numbers are there :"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Array after sorting is : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
return 0;
}

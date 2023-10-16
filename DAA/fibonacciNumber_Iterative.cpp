#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    int f0=0,f1=1;
    int fn=0;
    for(int i=0;i<n;i++)
    {
        cout<<f0<<" ";
        fn=f0+f1;
        f0=f1;
        f1=fn;
    }
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The fibonacci Series is: ";
    fib(n);

}
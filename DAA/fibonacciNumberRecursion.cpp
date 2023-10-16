#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n==0 || n==1)
    {
        // cout<<n<<endl;
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The fibonacci Series is: ";
     for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }

}
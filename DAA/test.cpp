#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;

    int value[n];
    int weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int dp[n+1][w+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(j>=weight[i-1])
            {
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;;


}
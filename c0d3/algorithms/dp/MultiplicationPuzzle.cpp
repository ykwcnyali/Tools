#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int dp[125][125];
int a[125];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int len=1;len<n;len++)
        {
            for(int i=1;i<n-1;i++)
            {
                int j=i+len;
                dp[i][j]=0x3f3f3f3f;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[k]*a[i-1]*a[j]);
                }
            }
        }
        printf("%d\n",dp[1][n-1]);
    }
}

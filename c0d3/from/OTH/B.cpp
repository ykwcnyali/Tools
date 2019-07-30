#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 50050
int a[N],n;
int c[N];
long long qian[N],hou[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        c[i]+=v;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        ans+=c[i];
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                qian[i]=sum(a[i]);
                add(a[i],1);
            }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--)
        {
            hou[i]=n-i-sum(a[i]);
            add(a[i],1);
        }
        for(int i=n-1;i>=1;i--)
            hou[i]=hou[i]+hou[i+1];
        long long ans=0;
        for(int i=1;i<n;i++)
                ans+=qian[i]*hou[i+1];
        printf("%lld\n",ans);
    }
    return 0;
}

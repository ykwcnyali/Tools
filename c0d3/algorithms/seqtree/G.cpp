#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define ll long long
using namespace std;

int n,m,a[N],f[N];
ll c[N];

void ins(int x,int y)
{
    while (x<=n)
    {
        c[x]+=y;
        x+=x&(-x);
    }
}

ll query(int x)
{
    ll ans=0;
    while (x)
    {
        ans+=c[x];
        x-=x&(-x);
    }
    return ans;
}

int find(int x)
{
    if (f[x]==x) return x;
    f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ins(i,a[i]);
    }
    for (int i=1;i<=n+1;i++)
        f[i]=i;
    for (int i=1;i<=n;i++)
        if (a[i]<=1) f[find(i)]=find(i+1);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if (op==1)
        {
            printf("%lld\n",query(r)-query(l-1));
        }else
        {
            if (a[l]<=1) l=find(l+1);
            while (l<=r)
            {
                ins(l,-a[l]);
                a[l]=sqrt(a[l]);
                ins(l,a[l]);
                if (a[l]<=1) f[find(l)]=find(l+1);
                l=find(l+1);
            }
        }
    }
    return 0;
}


#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include<stack>
using namespace std;
const int maxn=100+10;
int a[maxn];
int n,k;
vector<int >nex[maxn];
int dp[maxn][maxn];
bool vis[maxn];
inline void DP(int x){
    dp[x][1]=a[x]; 
    for(int i=0;i<nex[x].size();i++){
        int y=nex[x][i];
        if(vis[y])  continue;
        vis[y]=1;
        DP(y);                              
        for(int all=k;all>=1;all--){
            for(int ori=1;ori<=all;ori++){
                dp[x][all]=max(dp[x][ori]+dp[y][all-ori ]   ,dp[x ][all]);
            }
        }
    }
}
int main(){
    int i,j,x,y;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++){
            nex[i].clear();
            scanf("%d",&a[i]);
            for(int j=1;j<=k;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&x,&y);
            nex[x].push_back(y);
            nex[y].push_back(x);
        }
        memset(vis,0,sizeof vis);
        vis[0]=1;
        DP(0);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i][k]);
         printf("%d\n",ans);
    }
 }

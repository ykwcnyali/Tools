#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10001;
vector<int> G[MAXN],Road[MAXN];
int dis[MAXN],zg[MAXN];
bool vis[MAXN];
#define push(x) push_back(x)
inline void dfs(int x){
    int i;
    dis[x] = zg[x] = 0;
    for(i = 0;i < G[x].size();i++){
        int v = G[x][i],w = Road[x][i];
        if(!vis[v]){
            vis[v] = 1;
            dfs(v);
            G[v].push(w);
            G[v].push(x);
            if(dis[v] + w > dis[x]){
                zg[x] = dis[x];
                dis[x] = dis[v] + w;
            }
            else if(dis[v] + w > zg[x])
                zg[x] = dis[v] + w;
        }
    }
}
int main(){
    int n,i;
	ios::sync_with_stdio(0);
    while(~scanf("%d",&n)){
        for(i = 1;i <= n;i++) G[i].clear(),Road[i].clear();
        memset(vis,0,sizeof(vis));
        for(i = 2;i <= n;i++){
            int u,w;
			cin>>u>>w;
            G[i].push(u),G[u].push(i);
            Road[i].push(w),Road[u].push(w);
        }
        vis[1] = 1;
        dfs(1);
        printf("%d\n",dis[1]);
        for(i = 2;i <= n;i++){
            int R = 0,mid = i,fa = G[i][G[i].size() - 1],distance = G[i][G[i].size() - 2];
            int meter = distance;
            while(1){
                if(dis[fa] == dis[mid] + distance)
                    R  = max(meter + zg[fa],R);
                else R = max(R,dis[fa] + meter);
                if(fa == 1) break;
                mid = fa;
                distance = G[fa][G[fa].size() - 2],fa = G[fa][G[fa].size() - 1];
                meter += distance;
            }
            printf("%d\n",max(R,dis[i]));
        }
    }
    return 0;
}

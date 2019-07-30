#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10000+10
int n;
vector<int> path[10003];
inline void readit() {
    cin>>n;
    for (register int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    return;
}
int dep[maxn],grand[maxn];
int ans;
int vis[maxn];
inline void build(int root) {
    for(register int i=0;i<path[root].size();++i) {
        int son=path[root][i];
        if(dep[son]>0)continue;
        dep[son]=dep[root]+1,grand[son]=root;
        build(son);
    }
    if(!vis[root]){
        ++ans;
        int pos=grand[root];
        vis[pos]=1;
        for (register int i=0;i<path[pos].size();++i) 
            vis[path[pos][i]]=1;
    }
    return;
}
int main(){
    readit();
    memset(dep,0,sizeof dep);
    dep[1]=1; grand[1]=1;
    build(1);
    cout<<ans;
    return 0;
}

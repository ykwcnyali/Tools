#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1001
int m,t,n,dis[maxn];
int mmap[maxn][maxn];
bool vis[maxn];
inline void init(){
	memset(mmap,0,sizeof mmap);
}
inline void dij(){
	memset(dis,0,sizeof dis);
	dis[1]=0;
	for(register int i=2;i<=n;i++)dis[i]=mmap[1][i];
	for(register int i=1;i<n;i++){
		int x=0,m=0;//keep: m=mindis,dis[x]==m;
		//x is which point be choosed, because dis[x] is the minniest in all of dis[i] (i belongs to [1,n])
		//find x and its value:
		for(register int j=1;j<n;j++){
			if(vis[j]==0 and dis[j]>m){
				x=i;
				m=dis[x];
			}
		}
		vis[x]=1;
		//update the dis[] to all points
		for(register int j=1;j<=n;j++){
			if(mmap[x][j]==0)continue;
			dis[j]=max(dis[j],min(dis[x],mmap[x][i]));
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	int tt=1;
	while(tt<=t){
		init();
		cin>>n>>m;
		for(register int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			mmap[x][y]=mmap[y][x]=z;
		}
		dij();
		cout<<"Scenario #"<<tt<<":"<<endl<<dis[n]<<endl;
		tt++;
	}
	return 0;
}

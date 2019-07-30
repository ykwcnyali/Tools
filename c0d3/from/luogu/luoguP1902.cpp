#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define inf 1008
int n,m,l,r=inf,ans;
int a[maxn][maxn];
bool v[maxn][maxn];
bool flag=0;
inline bool judge(){
	for(register int i=1;i<=m;i++){
		if(v[n][i]==0)return 0;
	}
	return 1;
}
inline void dfs(int goal,int hurt,int x,int y){
	if(judge()){
		if(hurt<=goal)flag=1;
		return;
	}
	if(x<n and v[x+1][y]==0){
		v[x+1][y]=1;
		dfs(goal,max(hurt,a[x+1][y]),x+1,y);
		v[x+1][y]=0;
	}
	if(y<n and v[x][y+1]==0){
		v[x+1][y]=1;
		dfs(goal,max(hurt,a[x][y+1]),x,y+1);
		v[x][y+1]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	while(l<=r){
		int mid=(l+r)>>1;
		dfs(mid,0,1,1);
		if(flag){
			r=mid;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

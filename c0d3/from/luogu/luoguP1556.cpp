#include<bits/stdc++.h>
using namespace std;
#define maxn 20+1
struct node{
	bool vis;
	int x,y;
}p[maxn];
int n,ans;
inline int dir(int x1,int y11,int x2,int y2){
	if(x1==x2){
		if(y11<y2)return 1;
		else return 2;
	}
	if(y11==y2){
		if(x1<x2)return 3;
		else return 4;	
	}
	return 0;
}
inline void dfs(int x,int y,int d,int to){
	if(to>n){
		if((x==0 or y==0) and dir(x,y,0,0)!=d)ans++;
		return;
	}
	for(register int i=1;i<=n;i++){
		if(p[i].vis==0 and (p[i].x==x or p[i].y==y) and dir(x,y,p[i].x,p[i].y)!=d){
			p[i].vis=1;
			dfs(p[i].x,p[i].y,dir(x,y,p[i].x,p[i].y),to+1);
			p[i].vis=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}

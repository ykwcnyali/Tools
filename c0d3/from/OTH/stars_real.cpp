#include<iostream>
#include<cmath>
#define maxn 15010
using namespace std;
inline int lowbit(int x){
	return x&-x;
}
struct node{
	int x,y;
}p[maxn];
int n,m=32001;
int c[maxn<<2],ans[maxn<<2];
inline void upd(int x,int y){
	while(x<=m){
		c[x]+=y;
		x+=lowbit(x);
	}
}
inline int sum(int x){
	int res=0;
	while(x>0){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(register int i=1;i<=n;i++){
		int u=p[i].x+1;
		int v=sum(u);
		upd(u,1);
		ans[v]++;
	}
	for(register int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define inf 0x3f3f3f3f
int n,ans=inf;
int l,r;
struct node{
	int x,y,fa;
}c[maxn];
inline int dis(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int findfa(int a){
	if(c[a].fa==a)return a;
	else return c[a].fa=findfa(c[a].fa);
}
inline void uni(node a,node b){
	b.fa=a.fa;
}
inline void init(){
	for(register int i=0;i<maxn;i++)c[i].fa=i;
}
inline bool judge(int maxdis){
	for(register int i=1;i<=n;i++){
		for(register int j=i+1;j<=n;j++){
			if(dis(c[i],c[j])<=maxdis)uni(c[i],c[j]);
		}
	}
	int rt=c[1].fa;
	for(register int i=2;i<=n;i++){
		if(c[i].fa!=rt){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
	}
	for(register int i=1;i<=n;i++){
		for(register int j=i+1;j<=n;j++){
			r=max(r,dis(c[i],c[j]));
		}
	}
	cout<<r<<endl;
	while(l<=r){
		int mid=(l+r)>>1;
		init();
		if(judge(mid)){
			r=mid;
			ans=min(ans,mid);
		}
		else {
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

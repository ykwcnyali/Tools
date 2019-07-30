//poj2031 by yalikiwi
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define maxn 110
using namespace std;
struct cell{
	int x,y,z,r;
}a[maxn];
struct edge{
	int u,v;
	double len;
}b[maxn*maxn];
int fa[maxn],n;
inline int findfa(int x){
	if(x==fa[x]){
		return x;
	}
	else {
		return fa[x]=findfa(fa[x]);
	}
}
inline void uni(int x,int y){
	fa[x]=y;
}
inline bool cmp(edge x,edge y){
	return x.len<y.len;
}
inline double caldis(cell p,cell q){
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)+(p.z-q.z)*(p.z-q.z));
}
inline void init(int n){
	for(register int i=1;i<=n;i++){	
		fa[i]=i;
	}
}
int main(){
	ios::sync_with_stdio(0);
	while(1){
		cin>>n;
		if(n==0)return 0;
		init(n);
		int cnt=1;
		for(register int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
		}
		for(register int i=1;i<=n;i++){
			for(register int j=i+1;j<=n;j++){
				b[cnt].u=i;
				b[cnt].v=j;
				b[cnt].len=max(0.0,caldis(a[i],a[j])-a[i].r-a[j].r);
				cnt++;
			}
		}
		sort(b+1,b+cnt+1,cmp);
		double sum=0;
		for(register int i=1;i<=cnt;i++){
			if(findfa(b[i].u)!=findfa(b[i].v)){
				uni(b[i].u,b[i].v);
				sum+=b[i].len;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}

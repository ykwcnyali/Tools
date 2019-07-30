#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000+10
int n,m;
int s[maxn],fa[maxn],mins[maxn],alive[maxn],minto[maxn];
inline void init(){
	for(register int i=1;i<=n;i++){
		fa[i]=i;
		alive[i]=1;
		mins[i]=s[i];
		minto[i]=i;
	}
}
inline int findfa(int xx){
	if(fa[xx]==xx)return xx;
	else return fa[xx]=finafa(fa[xx]);
}
inline void uni(int xx,int yy){
	if(mins[findfa(xx)]<mins[findfa(yy)]){
		fa[x]=y
	}
}
int main(){
	ios::sync_with_stdio(0):
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>s[i];
	}
	init();
	cin>>m;
	for(register int i=1;i<=m;i++){
		char fuck;
		cin>>fuck;
		if(fuck=='M'){
			int x,y;
			if(alive[x]==1 and alive[y]==1)uni(x,y);
		}
		else if(fuck=='K'){
			int x;
			cin>>x;
			if(alive[x]==0){
				cout<<0;
			}
			else {
				cout<<mins[findfa(x)];
				alive[minto[findfa(x)]]=0;
			}
			cout<<endl;
		}
	}
	return 0;
}

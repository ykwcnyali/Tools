#include<bits/stdc++.h>
using namespace std;
#define ll long long	
#define maxn 100000000
ll n,m;
ll c[maxn];
inline ll lowbit(ll x){
	return x&-x;
}
inline void upd(ll x,ll v){
	while(x<=n){
		c[x]+=v;
		x+=lowbit(x);
	}
}
inline ll cal(ll x){
	ll res=0;
	for(register int i=x;i>0;i-=lowbit(i)){
		res+=c[i];
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(register int i=1;i<=m;i++){
		int flag;
		cin>>flag;
		if(flag==1){
			ll x,y,w;
			cin>>x>>y>>w;
			upd(x,w);
			upd(y+1,-w);
		}
		if(flag==2){
			ll x,y;
			cin>>x>>y;
			cout<<cal(y)-cal(x-1)<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 500000+10
#define ll long long
ll n,m;
ll c[maxn],a[maxn];
inline ll lowbit(ll x){
	return x&-x;
}
inline void upd(int x,int y){
	while(x<=n){
		c[x]+=y;
		x+=lowbit(x);
	}
}
inline ll cal(int x){
	ll ans=0;
	while(x){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
		upd(i,a[i]);
	}
	for(register int i=1;i<=m;i++){
		int flag,x,y;
		cin>>flag>>x>>y;
		if(flag==1){
			upd(x,y);
		}
		else{
			cout<<cal(y)-cal(x-1)<<endl;
		}
	}
	return 0;
}

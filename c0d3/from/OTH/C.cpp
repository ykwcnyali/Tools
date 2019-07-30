#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100000+10
#define ll long long
ll c[maxn],n,m;
ll s[maxn];
inline int lowbit(ll x){
	return x&-x;
}
inline void upd(ll x,ll y){
	while(x<=n){
		c[x]+=y;
		x+=lowbit(x);
	}
}
inline int cal(ll x){
	ll res=0;
	while(x){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
inline void init(){
	memset(c,0,sizeof c);
}
int main(){
	ios::sync_with_stdio(0);
	while(1){
		cin>>n;
		if(n==0)return 0;
		init();
		ll cnt=0;
		cin>>m;
		for(register int i=1;i<=m;i++){
			ll l,r,w;
			cin>>l>>r>>w;
			upd(l,w);
			upd(r+1,-w);
		}
		for(register int i=1;i<=n;i++){
			s[i]=cal(i);
		}
		for(register int i=n-1;i>=1;i--){
			s[i]+=s[i+1];
		}
		cin>>m;
		for(register int i=1;i<=m;i++){
			int hp,pl;
			cin>>hp>>pl;
			if(s[pl]<hp){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

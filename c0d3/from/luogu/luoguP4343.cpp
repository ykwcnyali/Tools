#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define min_(x,y) ((x)>(y)?(y):(x))
#define max_(x,y) ((x)>(y)?(x):(y))
#define inf 0x7f7f7f7f
#define ll long long
ll l,k;
ll a[maxn];
bool flag;
ll lo=inf,hi;
ll tot;
inline bool judge(ll fuck){
	int cnt=0,sum=0;
	for(register int i=1;i<=l;i++){
		sum+=a[i];
		if(sum>=fuck){
			cnt++;
			sum=0;
		}
		else if(sum<0)sum=0;
	}
	if(cnt==k)return 1;
	else return 0;
}
inline void findlo(ll l,ll r){
	if(l==r-1){
		if(judge(l)){
			flag=1;
			lo=min_(lo,l);
		}
		if(judge(r)){
			flag=1;
			lo=min_(lo,r);
		}
		return;
	}
	int mid=(l+r)>>1;
	if(judge(mid)){
		flag=1;
		r=mid;
		lo=min_(lo,mid);
	}
	else {
		l=mid;
	}
	findlo(l,r);
}
inline void findhi(ll l,ll r){
	if(l==r-1){
		if(judge(l)){
			flag=1;
			hi=max_(hi,l);
		}
		if(judge(r)){
			flag=1;
			hi=max_(hi,r);
		}
		return;
	}
	ll mid=(l+r)>>1;
	if(judge(mid)){
		flag=1;
		l=mid;
		hi=max_(hi,mid);
	}
	else {
		r=mid;
	}
	findhi(l,r);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>l>>k;
	if(k>l){
		cout<<"-1";
		return 0;
	}
	for(register int i=1;i<=l;i++){
		cin>>a[i];
		tot+=a[i];
	}
	findlo(0,tot);
	findhi(0,tot);
	if(!flag){
		cout<<"-1";
		return 0;
	}
	cout<<lo<<" "<<hi;
	return 0;
}

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 100000+10
int c[maxn],n;
inline int lowbit(int x){
	return x&-x;
}
inline void upd(int x,int s,int len){
	while(x<=len){
		c[x]+=s;
		x+=lowbit(x);
	}
}
inline int calc(int x){
	int ans=0;
	while(x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
inline void init(){
	memset(c,0,sizeof c);
}
int main(){
	ios::sync_with_stdio(0);
	while(1){
		cin>>n;
		init();
		if(n==0){
			return 0;
		}
		for(register int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			upd(x,1,n);
			upd(y+1,-1,n);
		}
		for(register int i=1;i<n;i++){
			cout<<calc(i)<<" ";
		}
		cout<<calc(n)<<endl;
	}
	return 0;
}

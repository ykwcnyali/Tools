#include<bits/stdc++.h>
using namespace std;
#define maxn 10000000
int n,m,a[maxn],b[maxn],nn=1,mm=1;
int nf,ans;
long long tot;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		int t,v;
		cin>>v>>t;
		tot+=t;
		for(register int j=nn;j<=nn+t;j++){
			a[i]=v+a[i-1];
		}
		nn+=t+1;
	}
	for(register int i=1;i<=m;i++){
		int t,v;
		cin>>v>>t;
		for(register int j=mm;j<=mm+t;j++){
			b[i]=v+b[i-1];
		}
		mm+=t+1;
	}
	if(a[1]>b[1])nf=1;
	for(register int i=1;i<=tot;i++){
		if(nf==1 and a[i]<b[i]){
			nf=0;
			ans++;
		}
		else if(nf==0 and a[i]>b[i]){
			nf=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+10
int t;
int n,a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a[1]>>a[2];
		a[2]/=__gcd(a[1],a[2]);
		for(register int i=3;i<=n;i++){
			cin>>a[i];
			a[2]/=__gcd(a[2],a[i]);
		}
		if(a[2]==1){
			cout<<"Yes";
		}
		else cout<<"No";
		cout<<endl;
	}
	return 0;
}

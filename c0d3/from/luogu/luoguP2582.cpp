#include<bits/stdc++.h>
using namespace std;
#define maxn 800010
#define fr(i,1,n) for(register int i=1;i<=n;i++)
int f[maxn],g[maxn];
int c[maxn],d[maxn];
int x,si;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	fr(i,1,n){
		cin>>f[i];
	}
	fr(i,1,n){
		if(c[i])continue;
		x=i,si=0;
		while(x!=i){
			x=a[x];
			si++;
		}
		while(x!=i){
			x=a[x];
			c[x]=si;
		}
		if(!d[si]){
			d[si]=i;
			for(register int j=sqrt(si);j>0;j--){
				
			}
		}
	}
	return 0;
}

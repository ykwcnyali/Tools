#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
inline bool cmp(int x,int y){
	return x>y;
}
int a[maxn],n;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(register int i=1;i<=n;i++){
		if(a[i]<i){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
}

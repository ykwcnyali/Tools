#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
struct node{
	long long fa,son[maxn],dep,v,cntson;
}a[maxn];
int n;
long long ans,maxx;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		a[i].dep=1;
	}
	for(register int i=1;i<n;i++){
		cin>>x>>y;
		if(a[x].fa==0 and a[y].fa=0){
			a[x].cntson++;
			a[x].son[a[x].cntson]=y;
			a[y].fa=x;
			a[y].dep=a[x].dep+1;
		}
		if(a[x].fa==0 and a[y].fa!=0){
			a[x].fa=y;
			a[x].dep=a[y].dep+1;
			a[y].cntson++;
			a[y].son[cntson]=x;
		}

	}
	return 0;
}
//音孔 音量调节 12位 闹铃时间

/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：luoguP5459.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月18日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
int q[maxn],n;
int ans;
int L,R;
inline void work(int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	work(l,m);
	work(m+1,r);
	int t=l-1,h=l;
	for(int i=m+1;i<=r;i++){
		while(t+1<=m and q[i]>=q[t+1]+L)t++;
		while(h<=m and q[i]>q[h]+R)h++;
		ans+=t-h+1;
	}
	sort(q+l,q+r+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>L>>R;
	for(register int i=1;i<=n;i++){
		int a;
		cin>>a;
		q[i]=q[i-1]+a;
	}
	work(0,n);
	cout<<ans;
	return 0;
}

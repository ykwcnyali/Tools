/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：luoguP2780.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月30日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 250+10
int a[maxn],n,k,b;
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("&d&d*&d&d",&n,&k,&b);
	for(register int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(register int i=1;i<=k;i++)b-=a[i];
	cout<<b;
	return 0;
}

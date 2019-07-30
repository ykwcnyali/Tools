/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：luoguP5462.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月15日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define max_(a,b) ((a)>(b)?(a):(b))
int a[maxn];
int s;
int ans[maxn];
int nmax;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(register int i=1;i<=n/2;i++){
		for(register int j=1;j<=n+2-i*2;j++){
			if(a[j]>nmax)
		}
	}
	return 0;
}

/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：luoguP2544.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月19日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[3];
ll n,m,mod;
inline ll calc1(){
	ll sum=0;
	sum=floor(n/5);
	sum*=13;
	int ys=n%5;
	if(ys==1){
		sum+=2;
	}
	else if(ys==2){
		sum+=5;
	}
	else if(ys==3){
		sum+=8;
	}
	else if(ys==4){
		sum+=10;
	}
	return sum-1;
}
inline ll calc2(){
	ll sum=0;
	sum=floor(n/5);
	sum*=21;
	int ys=n%5;
	if(ys==1){
		sum+=3;
	}
	else if(ys==2){
		sum+=8;
	}
	else if(ys==3){
		sum+=11;
	}
	else if(ys==4){
		sum+=16;
	}
	return sum-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>mod;
	a[0]=calc1();
	if(m==1){
		cout<<a[0];
		return 0;
	}
	a[1]=calc2();
	for(register int i=3;i<=m;i++){
		a[2]=(a[0]+a[1])%mod;
		a[0]=a[1];
		a[1]=a[2];
	}
	cout<<a[1]%mod;
	return 0;
}

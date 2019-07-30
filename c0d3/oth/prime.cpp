/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：prime.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月14日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
inline bool judge(int x){
	for(register int i=2;i*i<=x;i++){
		if(x%i==0)return 0;
	}
	return 1;
}
int a[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(register int m=1;m<=12;m++){
		for(register int d=1;d<=a[m];d++){
			if(judge(20190000+m*100+d)){
				cout<<"2019."<<m<<"."<<d<<endl;
			}
		}
	}
	return 0;
}

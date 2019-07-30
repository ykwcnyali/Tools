/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：luoguP4176.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月19日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 110
#define maxi 2
int dp[maxi][maxn];
bool flag;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n;
	for(register int i=1;i<=m;i++)
		dp[0][i]=i*2;
	dp[0][0]=dp[1][0]=1;
	for(register int i=2;i<=n;i++){
		flag=1-flag;
		for(register int j=1;j<=m;j++){
			dp[flag][j]=dp[1-flag][j-1]+dp[flag][j-1];
		}
	}
	cout<<dp[flag][m];
	return 0;
}

/*==============================================================
*   
*   文件名称：luoguP2679.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月20日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define maxm 200+10
#define mod 1000000007
#define min_(a,b) ((a)>(b)?(b):(a))
#define ll long long
int n,m,k;
ll dp[maxm][maxm];
ll qi[maxm][maxm];
char a[maxn],b[maxm];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	scanf("%s%s",&a+1,&b+1);
	qi[0][0]=1;
	for(register int i=1;i<=n;i++){
		for(register int j=min_(i,m);j>=1;j--){
			for(register int p=min_(k,j);p>=1;p--){
				if(a[i]==b[j])
					dp[j][p]=(dp[j-1][p]+qi[j-1][p-1])%mod;
				else dp[j][p]=0;
				qi[j][p]+=dp[j][p];
				qi[j][p]%=mod;
			}
		}
	}
	cout<<qi[m][k];
	return 0;
}

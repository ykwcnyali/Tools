/*================================================================
*   
*   文件名称：luoguP5468.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月17日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn (100000+10)
#define inf 0x3f3f3f3f
#define ll long long
#define max_(x,y) ((x)>(y)?(x):(y))
#define min_(x,y) ((x)>(y)?(y):(x))
struct way{
	ll x,y,p,q;

}a[maxn<<1];
int dp[maxn][1000+10];
ll n,m,A,B,C,ans=inf,maxt;
inline ll calc(int x){
	return A*x*x+B*x+C;
}
inline bool cmp(way fi,way se){
	return fi.p<se.p;
}
inline void init(){
	memset(dp,0x3f,sizeof dp);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>A>>B>>C;
	for(register int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].p>>a[i].q;
		maxt=max_(maxt,a[i].q);
	}
	sort(a+1,a+m+1,cmp);
	init();
	dp[1][0]=0;
	for(register int i=1;i<=m;i++){
		for(register int j=0;j<=a[i].p;j++){
			if(dp[a[i].x][j]!=inf){
				dp[a[i].y][a[i].q]=min_(dp[a[i].y][a[i].q],dp[a[i].x][j]+calc(a[i].p-j));
			}
		}
	}
	for(register int i=0;i<=maxt;i++){
		ans=min_(ans,i+dp[n][i]);
	}
	cout<<ans;
	return 0;
}

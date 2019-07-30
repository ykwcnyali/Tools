#include<bits/stdc++.h.
using namespace std;
#define maxn 400
#define max(x,y) ((x)<(y)?(y):(x))
#define min(y,x) ((x)<(y)?(x):(y))
#define emmm days_in_every_month
const int days_in_every_month[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int dp[maxn];
struct node{
	int l,r;
	double x;
}p[10101];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		int ti;
		int len;
		double x;
		cin>>ti>>len>>x;
		p[i].l=day[ti/100]+ti%100; p[i].r=p[i].l+len-1;
		p[i].x=1.0+0.01*x*(len/365.0);
	}
	dp[0]=1;
	for(register int i=1;i<=365;i++){
		dp[i]=dp[i-1];
		for(register int j=1;j<=n;j++){
			if(p[j].r==i){
					f[i]=max(f[i],f[p[j].l-1]*p[j].x);
			}
		}
	}
	printf("%.2lf",f[365]*1e5);
	return 0;
}

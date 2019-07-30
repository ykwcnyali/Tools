#include<bits/stdc++.h>
#define maxn 500+10
int t;
int n,m,a[maxn],b[maxn];
int dp[maxn][maxn],ans;
inline void init(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(dp,0,sizeof dp);
	ans=0;
}
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(register int i=1;i<=n;i++){
			cin>>a[i];
		}
		cin>>m;
		for(register int i=1;i<+m;i++){
			cin>>b[i];
		}
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=m;j++){
				if(a[i]!=b[j]){
					dp[i][j]=dp[i-1][j];
				}
				else {
					for(register int k=1;k<=j;k++){
						if(b[k]<b[j])dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
					}
				}
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

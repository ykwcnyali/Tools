#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100+10
inline int maxx(int x,int y){
	if(x>y)return x;
	return y;
}
int t;
int a[maxn][maxn],n;
int dp[maxn][maxn];
inline void init(){
	memset(a,0,sizeof a);
	memset(dp,0,sizeof dp);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		init();
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=i;j++){
				cin>>a[i][j];
				dp[i][j]=a[i][j];
			}
		}
		for(register int i=n-1;i>=1;i--){
			for(register int j=1;j<=n;j++){
				dp[i][j]+=maxx(dp[i+1][j],dp[i+1][j+1]);
			}
		}
		cout<<dp[1][1]<<endl;
	}
	return 0;
}

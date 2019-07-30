#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define mod 10007
int t,cnt;
char s[maxn];
int dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cnt++;
		cout<<"Case "<<cnt<<":";
		cin>>s;
		int len=strlen(s);
		memset(dp,0,sizeof dp);
		for(register int i=0;i<len;i++){
			for(register int j=i;j>=0;j--){
				if(i==j){
					dp[i][j]=1;
					continue;
				}
				if(s[i]==s[j])
					dp[i][j]+=dp[i-1][j+1]+1;
				dp[i][j]+=(5*mod+dp[i-1][j]+dp[i][j+1]+-dp[i-1][j+1])%mod;
			}
		}
		cout<<dp[len][1]%mod<<endl;
	}
	return 0;
}

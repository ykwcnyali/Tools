#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100+10
int a[maxn],dp[maxn][maxn];
char s[maxn];
inline void init(){
	memset(dp,0,sizeof dp);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		cin>>s;
		if(s[0]=='e')break;
		init();
		for(register int i=0;i<strlen(s);i++){
			if(s[i]=='(')a[i+1]=1;
			else if(s[i]==')')a[i+1]=2;
			else if(s[i]=='[')a[i+1]=3;
			else if(s[i]==']')a[i+1]=4;
		}
		int n=strlen(s)+1;
		for(register int i=0;i<n;i++){
			for(register int j=1;j<=n;j++){
				if((a[j]==1 and a[j+i]==2) or (a[j]==3 and a[j+i]==4)){
					dp[j][j+i]=dp[j+1][j+i-1]+2;
				}
				for(register int k=0;k<i;k++){
					dp[j][i+j]=max(dp[j][j+i],dp[j][j+k]+dp[j+k+1][j+i]);
				}
			}
		}
		cout<<dp[1][n];
	}
	return 0;
}

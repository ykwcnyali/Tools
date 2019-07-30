#include<bits/stdc++.h>
using namespace std;
#define maxn 10
bool s[(1<<maxn)+1][(1<<maxn)+1];
int n;
int m[11]={1,2,4,8,16,32,64,128,256,512,1024};
int main(){
	#ifdef ONLINE_JUDGE
	#endif	
		freopen("luoguP5461.in","r",stdin);
		freopen("luoguP5461.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=m[n];i++){
		for(register int j=1;j<=m[n];j++){
			if(i==m[n] or j==m[n]){
				s[i][j]=1;
			}
			else if(s[i-1][j]-s[i-1][j+1]){
				s[i][j]=1;
			}
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

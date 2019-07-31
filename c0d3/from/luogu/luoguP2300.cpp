/*================================================================
*   
*   文件名称：luoguP2300.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月31日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
#define ll long long
ll sum[maxn],n,ans[maxn],la[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll i,j;
	for(register int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum[i]=sum[i-1]+a;
	}
	for(i=1;i<=n;i++){
		for(j=i-1;j>=0;j--){
			if(sum[i]-sum[j]>=la[j])
				break;
		}
			ans[i]=ans[j]+i-j-1;
			la[i]=sum[i]-sum[j];
	}
	cout<<ans[n];
	return 0;
}

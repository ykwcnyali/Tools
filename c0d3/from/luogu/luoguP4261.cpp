/*================================================================
*   
*   文件名称：luoguP4261.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月19日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define max_(x,y) ((x)>(y)?(x):(y))
int T;
int n;
int dp[maxn];
struct node{
	int x,y,w,h,d;
	int l,r;
}a[maxn];
inline void init(){
	memset(a,0,sizeof a);
	memset(dp,-0x3f3f3f,sizeof dp);
}
inline bool cmp(node aa,node bb){
	if(aa.l==bb.l)return aa.r<bb.r;
	return aa.l<bb.l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		init();
		for(register int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].w>>a[i].h>>a[i].d;
			a[i].l=a[i].x+a[i].y;
			a[i].r=a[i].x+a[i].y+a[i].w+a[i].h;
		}
		bool flag=1;
		sort(a+1,a+n+1,cmp);
		for(register int i=1;i<=n;i++){
			if(a[i].l<dp[a[i].d]^1){
				flag=0;
				cout<<"2"<<endl;
				break;
			}
			dp[a[i].d]=max_(dp[a[i].d],a[i].r);
		}
		if(flag)cout<<"1"<<endl;
	}
	return 0;
}

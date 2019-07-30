/*================================================================
*   
*   文件名称：luoguP3958.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月20日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 1001
int n,h,r;
struct node{
	int x,y,z;
	int id;
}ho[maxn];
inline bool judge(node a,node b){
	if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)<r*r)return 1;
	return 0;
}
int fa[maxn];
inline int findfa(int a){
	if(fa[a]==a)return a;
	return fa[a]=findfa(fa[a]);
}
inline void uni(node a,node b){
	fa[b.id]=fa[a.id];
}
inline void init(){
	memset(ho,0,sizeof ho);
	for(register int i=1;i<=n;i++){
		fa[i]=i;
	}
}
inline void pre(int iid){
	ho[iid].id=iid;
	if(ho[iid].z-r<=0)ho[iid].but=1;
	if(ho[iid].z+r>=h)ho[iid].top=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		
	}
	return 0;
}

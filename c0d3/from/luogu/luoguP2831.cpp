// luogu-judger-enable-o2
/*================================================================
*   
*   文件名称：luoguP2831.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月20日
*   描    述：
*
================================================================*/


#include<bits/stdc++.h>
using namespace std;
#define maxn 20
#define db double
const db wc=1e-8;
struct bird{
    db x,y;
    bool vis;
}u[maxn],l[maxn];
struct line{
    db a,b;
}s[maxn];
inline bool judge(db a,db b){
    if(abs(a-b)<wc)return 1;
    return 0;
}
int n,m,ans;
inline void init(){
    ans=100;
    memset(u,0,sizeof u);
    memset(s,0,sizeof s);
}
inline void dfs(int nowin,int linked,int left){
    if(linked+left>=ans)return;
    if(nowin>n){
        ans=linked+left;
        return;
    }
    bool flag=0;
    for(register int i=1;i<=linked;i++){
        if(judge(s[i].a*u[nowin].x*u[nowin].x+s[i].b*u[nowin].x,u[nowin].y)){
            dfs(nowin+1,linked,left);
            flag=1;
            break;
        }
    }
    if(flag==0){
        for(register int i=1;i<=left;i++){
            if(judge(u[nowin].x,l[i].x))continue;
            db aa=(u[nowin].y*l[i].x-l[i].y*u[nowin].x)/(u[nowin].x*u[nowin].x*l[i].x-l[i].x*l[i].x*u[nowin].x);
            db bb=(u[nowin].y-u[nowin].x*u[nowin].x*aa)/u[nowin].x;
            if(aa<0){
                s[linked+1].a=aa;
                s[linked+1].b=bb;
                db q=l[i].x,w=l[i].y;
                for(register int j=i;j<left;j++){
                    l[j].x=l[j+1].x;
                    l[j].y=l[j+1].y;
                }
                dfs(nowin+1,linked+1,left-1);
                for(register int j=left;j>i;j--){
                    l[j].x=l[j-1].x;
                    l[j].y=l[j-1].y;
                }
                l[i].x=q;
                l[i].y=w;
            }
        }
        l[left+1].x=u[nowin].x;
        l[left+1].y=u[nowin].y;
        dfs(nowin+1,linked,left+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        init();
        cin>>n>>m;
        for(register int i=1;i<=n;i++){
            cin>>u[i].x>>u[i].y;
        }
        dfs(1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

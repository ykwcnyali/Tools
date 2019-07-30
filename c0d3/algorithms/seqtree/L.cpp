#include<iostream>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
int n,m;
int a[N];
int MAX[N<<2];
void PushUp(int rt){
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);
}
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void update(int p,int sc,int l,int r,int rt) {
    if (l==r){
        MAX[rt]= sc;
        return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
 
    PushUp(rt);
}
void build(int l,int r,int rt){
    if (l==r){
        scanf("%d",&MAX[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
    if ( L<=l&&r<=R ){
        return MAX[rt];
    }
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m){
        int res = query(L,R,lson);
        ret = max(ret,res);
    }
    if (R>m){
        int res = query(L,R,rson);
        ret = max(res,ret);
    }
    return ret;
}
int main(){
        while (~scanf("%d%d",&n,&m)){
            build(1,n,1);
            while(m--){
                char opt[10];
                int a,b;
                scanf("%s%d%d",opt,&a,&b);
                if (opt[0]=='Q') printf("%d\n",query(a,b,1,n,1));
                else update(a,b,1,n,1);
            }
        }
    return 0;
}

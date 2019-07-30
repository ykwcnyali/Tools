#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define A 5000010
using namespace std;
struct node{
    int l,r,w;
    node(){
        w=0;
    }
}tree[A];
struct Node{
    int x,id;
}val[A];
bool cmp(Node a,Node b){
    return a.x<b.x;
}
int root[A],rank[A],cnt;
inline void update(int num,int &rt,int l,int r){
    tree[cnt++]=tree[rt];
    rt=cnt-1;
    tree[rt].w++;
    if(l==r)
      return;
    int m=l+r>>1;
    if(num<=m)
      update(num,tree[rt].l,l,m);
    else update(num,tree[rt].r,m+1,r);
}
inline int query(int i,int j,int k,int l,int r){
    int x=tree[tree[j].l].w-tree[tree[i].l].w;
    if(l==r)
      return l;
    int m=l+r>>1;
    if(k<=x)
      return query(tree[i].l,tree[j].l,k,l,m);
    else return query(tree[i].r,tree[j].r,k-x,m+1,r);
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i].x);
        val[i].id=i;
    }
    sort(val+1,val+n+1,cmp);
    for(int i=1;i<=n;i++)
      rank[val[i].id]=i;
    cnt=1;
    root[0]=0;
    tree[0].l=tree[0].r=tree[0].w=0;
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        update(rank[i],root[i],1,n);
    }
    int l,r,k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",val[query(root[l-1],root[r],k,1,n)].x);
    }
}

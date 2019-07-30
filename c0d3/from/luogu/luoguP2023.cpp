#include<cstdio>
#include<cstring>
struct nod{int l,r,ll,rr;long long c,k,ce;}a[400010];
int len,p;long long f[200010];
void bt(int l,int r){
    len++;int now=len;
    a[len].l=l;a[len].r=r;
    a[len].ll=a[len].rr=a[len].k=a[len].c=0;
    a[now].ce=1;
    if(l<r){
        int mid=(l+r)/2;
        a[now].ll=len+1;bt(l,mid);
        a[now].rr=len+1;bt(mid+1,r);
        a[now].c=a[a[now].ll].c+a[a[now].rr].c;
    }
    else a[len].c=f[l]%p;
}
void up(int now){
    int l=a[now].l,r=a[now].r,ll=a[now].ll,rr=a[now].rr,m=(l+r)/2;
    a[ll].c=(a[ll].c*a[now].ce+a[now].k*(m-l+1))%p;
    a[rr].c=(a[rr].c*a[now].ce+a[now].k*(r-m))%p;
    a[ll].ce=(a[ll].ce*a[now].ce)%p;
    a[rr].ce=(a[rr].ce*a[now].ce)%p;
    a[ll].k=(a[ll].k*a[now].ce+a[now].k)%p;
    a[rr].k=(a[rr].k*a[now].ce+a[now].k)%p;
    a[now].ce=1;
    a[now].k=0;
    return ;
}
void change(int now,int l,int r,long long k){
    if(a[now].l==l&&a[now].r==r){
        a[now].c=(a[now].c+k*(r-l+1))%p;
        a[now].k=(a[now].k+k)%p;
        return;
    }
    int ll=a[now].ll,rr=a[now].rr,mid=(a[now].l+a[now].r)/2;
    up(now);
    if(r<=mid) change(ll,l,r,k);
    else if(l>mid) change(rr,l,r,k);
    else{change(ll,l,mid,k); change(rr,mid+1,r,k);}
    a[now].c=(a[ll].c+a[rr].c)%p;
}
void cc(int now,int l,int r,long long k){
    if(a[now].l==l&&a[now].r==r){
        a[now].c=a[now].c*k%p;
        a[now].ce=(a[now].ce*k)%p;
        a[now].k=(a[now].k*k)%p; 
        return;
    }
    int ll=a[now].ll,rr=a[now].rr,mid=(a[now].l+a[now].r)/2;
    up(now);
    if(r<=mid) cc(ll,l,r,k);
    else if(l>mid) cc(rr,l,r,k);
    else{cc(ll,l,mid,k); cc(rr,mid+1,r,k);}
    a[now].c=(a[ll].c+a[rr].c)%p;
}
long long findsum(int now,int l,int r){
    if(a[now].l==l&&a[now].r==r) return a[now].c%p;
    int ll=a[now].ll,rr=a[now].rr,mid=(a[now].l+a[now].r)/2;
    up(now);
    if(r<=mid) return findsum(ll,l,r)%p;
    else if(l>mid) return findsum(rr,l,r)%p;
    else return (findsum(ll,l,mid)+findsum(rr,mid+1,r))%p;
}
int main(){
    int n,m;scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%lld",&f[i]);
    len=0;bt(1,n);scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int v;scanf("%d",&v);
        if(v==2){
            int x,y;long long c;scanf("%d %d %lld",&x,&y,&c);
            change(1,x,y,c);
        }
        else if(v==1){
            int x,y;long long c;scanf("%d %d %lld",&x,&y,&c);
            cc(1,x,y,c);
        }
        else{
            int x,y;scanf("%d %d",&x,&y);
            printf("%lld\n",findsum(1,x,y)%p);
        }
    }
    return 0;
}

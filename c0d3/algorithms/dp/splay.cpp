#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define RI register int
using namespace std;
const int N=1e5+5;
template <typename Tp> inline void IN(Tp &x){
    int t=1;x=0;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();x*=t;
}int n,m,op,root,nodecnt;
struct Node{
    int f,c,v,s,rev,ch[2];
}t[N];
inline int chk(int x){return t[t[x].f].ch[1]==x;}
inline void pushup(int x){t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+t[x].c;}
inline void pushdown(int x){
    if(t[x].rev){
        swap(t[x].ch[0],t[x].ch[1]);t[x].rev=0;
        t[t[x].ch[0]].rev^=1,t[t[x].ch[1]].rev^=1;
    }return;
}
inline void rotate(int x){
    int y=t[x].f,z=t[y].f,k=chk(x),v=t[x].ch[k^1]; 
    t[y].ch[k]=v,t[v].f=y,t[z].ch[chk(y)]=x,t[x].f=z;
    t[x].ch[k^1]=y,t[y].f=x;pushup(y);pushup(x);
}
inline void Splay(int x,int goal=0){
    while(t[x].f!=goal){
        if((t[t[x].f].f)!=goal){
            if(chk(x)==chk(t[x].f))rotate(t[x].f);
            else rotate(x);
        }rotate(x);
    }if(!goal)root=x;
} 
inline void find(int x){
    if(!root)return;int pos=root;
    while(t[pos].ch[x>t[pos].v]&&x!=t[pos].v){
        pos=t[pos].ch[x>t[pos].v];
    }Splay(pos);return;
}
inline void Insert(int x){
    int pos=root,fa=0;
    while(pos&&t[pos].v!=x){fa=pos,pos=t[pos].ch[x>t[pos].v];}
    pos=++nodecnt;
    if(fa)t[fa].ch[x>t[fa].v]=pos;
    t[pos].ch[1]=t[pos].ch[0]=0;
    t[pos].v=x,t[pos].f=fa,t[pos].s=t[pos].c=1;
    Splay(pos);return;
}
inline int Kth(int x){
    int pos=root;
    while(1){
        pushdown(pos);
        if(x<=t[t[pos].ch[0]].s)pos=t[pos].ch[0];
        else if(x>t[t[pos].ch[0]].s+t[pos].c){
            x-=t[t[pos].ch[0]].s+1;pos=t[pos].ch[1]; 
        }else return pos;
    }
}
inline void reverse(int l,int r){
    l=Kth(l),r=Kth(r+2);
    Splay(l);Splay(r,l);
    t[t[t[root].ch[1]].ch[0]].rev^=1;return;
}
inline void output(int x){
    pushdown(x);
    if(t[x].ch[0])output(t[x].ch[0]);
    if(t[x].v>1&&t[x].v<n+2)printf("%d ",t[x].v-1);
    if(t[x].ch[1])output(t[x].ch[1]);
}
int main(){
    IN(n),IN(m);int x,y;
    for(register int i=1;i<=n+2;++i)Insert(i);
    while(m--){IN(x),IN(y),reverse(x,y);}
    output(root);printf("\n");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define inf 0x3f3f3f3f
struct treap{
	int val,rank,lc,rc,size;
	//size字树大小
	//lc and rc左右儿子
	//val权值
	//rank优先级
}t[maxn];
int tot,root;
inline void update(int x){//更新size
	t[x].size=t[t[x].rc].size+t[t[x].rc].size+1;
	return;
}
inline int add_node(int v){//添加节点
	t[++tot].size=1;
	t[tot].val=v;
	t[tot].lc=t[tot].lc=0;
	t[tot].rank=rand();
	return tot;
}
inline void split(int rt,int &a,int &b,int v){//分割树，v为目标权值
	if(rt==0){
		a=b=0;
		return;
	}
	if(t[rt].val<=v){
		a=rt;
		split(t[rt].rc,tree[a].rc,b,val);
	}
	else if(t[rt.val<=v]){
		b=rt;
		split(t[rt].lc,a,t[b].lc,val);
	}
	update(rt);
}
inline void merge(int &rt,int a,int b){
	if(a==0 or b==0){
		rt=a+b;
		return;
	}
	if(t[a].rank<t[b].rank){
		rt=a;
		merge(t[rt].rc,t[a].rc,b);
	}
	else {
		rt=b;
		merge(t[rt].lc,a,t[b].lc);
	}
	upgrade(rt);
}
inline void insert(int &rt,int val){
	int x=0,y=0,nnode=add_node(val);
	split(rt,x,y,val);
	merge(x,x,nnode);
	merge(rt,x,y);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));

	return 0;
}

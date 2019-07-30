#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define maxn 50010
#define sc strcmp
using namespace std;
int t;
int a[maxn],m=100000,c[maxn],n;
inline int lowbit(int x){
	return x&-x;
}
inline void upd(int x,int y){
	while(x<=n){
		c[x]+=y;
		x+=lowbit(x);
	}
}
inline int cal(int x){
	int res=0;
	while(x){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
inline void init(){
	memset(c,0,sizeof c);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	char ch[30];
	int flag=1;
	while(t--){
		int x,y;
		init();
		cout<<"Case "<<flag<<":"<<endl;
		flag++;
		cin>>n;
		for(register int i=1;i<=n;i++){
			cin>>a[i];
			upd(i,a[i]);
		}
		while(~scanf("%s",ch)){
			if(sc(ch,"Query")==0){
				cin>>x>>y;
				cout<<cal(y)-cal(x-1)<<endl;
			}
			else if(sc(ch,"Add")==0){
				cin>>x>>y;
				upd(x,y);
			}
			else if(sc(ch,"Sub")==0){
				cin>>x>>y;
				upd(x,-y);
			}
			else break;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
int d[maxn][maxn];
int n;
struct node{
	int x,y;
}c[maxn];
inline int cal(node a,node b){
	return  (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
	}
	for(register int i=1;i<n;i++){
		for(register int j=i+1;j<=n;j++){
			d[i][j]=d[j][i]=cal(c[i],c[j]);
		}
	}
	
	return 0;
}

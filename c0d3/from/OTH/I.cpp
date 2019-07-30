#include<iostream>
#include<cstring>
using namespace std;
#define N 5
#define inf 0x3f3f3f3f
struct z{
	int x,y;
}c[20];
int a[N][N],b[N][N];
int w[N][N][N][N];
bool vis[N][N];
int sum;
int ans=inf;
inline int findabs(int x){
	if(x>=0)return x;
	return x*(-1);
}
inline int findmin(int x,int y){
	if(x>y)return y;
	return x;
}
inline void dfs(int pos,int v){
	if(pos>sum){
		ans=findmin(ans,v);
		return;
	}
	for(register int i=1;i<=4;i++){
		for(register int j=1;j<=4;j++){
			if(w[c[pos].x][c[pos].y][i][j]!=0 and vis[i][j]==0){
				vis[i][j]=1;
				dfs(pos+1,v+w[c[pos].x][c[pos].y][i][j]);
				vis[i][j]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	char ss;
	for(register int i=1;i<=4;i++){
		for(register int j=1;j<=4;j++){
			cin>>ss;
			a[i][j]=ss-'0';
		}
	}
	for(register int i=1;i<=4;i++){
		for(register int j=1;j<=4;j++){
			cin>>ss;
			b[i][j]=ss-'0';
			if(a[i][j]==b[i][j]){
				a[i][j]=b[i][j]=0;
			}
		}
	}
	for(register int i=1;i<=4;i++){
		for(register int j=1;j<=4;j++){
			if(a[i][j]){
				sum++;
				c[sum].x=i;
				c[sum].y=j;
				for(register int k=1;k<=4;k++){
					for(register int l=1;l<=4;l++){
						if(b[k][l]){
							w[i][j][k][l]=findabs(i-k)+findabs(j-l);	
						}
					}
				}
			}
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

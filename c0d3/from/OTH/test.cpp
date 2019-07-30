#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1111
using namespace std;
struct node{
	bool l,r,d;
	void read(){
		cin>>l>>r>>d;
	}
}a[maxn][maxn];
int n,lu[maxn][maxn],ld[maxn][maxn],ru[maxn][maxn],rd[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=n;i++{
		for(register int j=1;j<=i;j++){
			if(a[i][j].l)lu[i][j]=lu[i-1][j]+1;
			if(a[i][j].r)ru[i][j]=ru[i-1][j-1]+1;
		}
	}
	for(int i=n;i;i--){
		for(register int j=i;j;j--){
			if(a[i+1][j].r) ld[i][j]=ld[i+1][j+1]+1;
            if(a[i+1][j+1].l) rd[i][j]=rd[i+1][j]+1;
	}
	int ans=0;
	for(register int i=1;i<=n;i++0{
		for(register int j=1;j<=n;j++{
			for(register int k=j; a[i][k].d && k<=n && (k-j+1)<=lu[i][j]; ++k) {
                ans+=(k-j+1)<=ru[i][k];
            }
            for(register int k=j; a[i][k].d && k<=n && (k-j+1)<=ld[i][j]; ++k) {
                ans+=(k-j+1)<=rd[i][k];
            }
		}
	}
	cout<<ans;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
const int N=1e6+5;
const int M=20;
int logg[N],f[N][M+5],z[N][M+5],a[N];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	logg[0]=-1;
	for(int i=1;i<=n;i++){
		f[i][0]=z[i][0]=a[i];
		logg[i]=logg[i>>1]+1;
	}
	for(int j=1;j<=M;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
			z[i][j]=min(z[i][j-1],z[i+(1<<j-1)][j-1]);
		}
	}
	for(int x,y,i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int s=logg[y-x+1];
		printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s])-min(z[x][s],z[y-(1<<s)+1][s]));
	}
	return 0;
}

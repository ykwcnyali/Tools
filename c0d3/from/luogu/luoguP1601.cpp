#include<bits/stdc++.h>
using namespace std;
#define maxn 500+10
int a[maxn],b[maxn];
int sa[maxn],sb[maxn];
int ans[maxn];
bool p[maxn];
char c[maxn];
int bt,bta,btb;
inline void read(){
	while(1){
		cin>>c[bta];
		if('0'<=c[bta] and c[bta]<='9');
		bta++;
	}
	for(register int i=0;i<bta;i++){
		if('0'<=c[i] and c[i]<='9')a[i+1]=c[i]-'0';
	}
	memset(c,0,sizeof c);
	cin>>c;
	while(1){
		cin>>c[btb];
		if('0'<=c[btb] and c[btb]<='9');
		btb++;
	}
	for(register int i=0;i<btb;i++){
		if('0'<c[i] and c[i]<'9')b[i+1]=c[i]-'0';
	}
	bt=max(bta,btb);
}
inline void out(){
	for(register int i=1;i<=bta;i++){
		cout<<a[i];
	}
	cout<<endl;
	for(register int i=1;i<=btb;i++){
		cout<<b[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	for(register int i=1;i<=bta;i++){
		sa[i]=a[bta+1-i];
	}
	for(register int i=1;i<=btb;i++){
		sb[i]=b[btb+1-i];
	}
	for(register int i=1;i<=bt+1;i++){
		if(p[i-1]){
			if(sa[i]+sb[i]==9){
				p[i]=1;
				ans[i]=0;
			}
			else if(sa[i]+sb[i]>=10){
				p[i]=1;
				ans[i]=sa[i]+sb[i]-9;
				p[i]=1;
			}
			else{
				ans[i]=sa[i]+sb[i]+1;
			}
		}
		else{
			if(sa[i]+sb[i]>=10){
				p[i]=1;
				ans[i]=sa[i]+sb[i]-10;
			}
			else {
				ans[i]=sa[i]+sb[i];
			}
		}
	}
	if(ans[bt+1])cout<<ans[bt+1];
	for(register int i=bt;i>=1;i--){
		cout<<ans[i];
	}
	cout<<endl;
	out();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 25
int n;
int a[maxn],d[maxn],cc;
inline bool judge(int p1,int p2,int p3,int p4){
	if(a[p2]-a[p1]==a[p4]-a[p3]){
		if(a[p3]-a[p2]==a[p1]+cc-a[p4]){
			return 1;
		}
	}
	return 0;
}
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>d[i];
		a[i]=a[i-1]+d[i];
	}
	cc=a[n];
	for(register int p1=1;p1<=n;p1++){
		for(register int p2=p1+1;p2<=n;p2++){
			for(register int p3=p2+1;p3<=n;p3++){
				for(register int p4=p3+1;p4<=n;p4++){
					ans+=judge(p1,p2,p3,p4);
					/*if(judge(p1,p2,p3,p4)){
						ans++;
						cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
					}*/
				}
			}
		}
	}
	cout<<ans<<endl;
	/*for(register int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}*/
	//cout<<cc;
	return 0;
}

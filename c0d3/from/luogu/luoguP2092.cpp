#include<bits/stdc++.h>
using namespace std;
int n,ans;
queue<long long> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=2;i*i<=n;i++){
		while(n%i==0){
			n/=i;
			q.push(i);
		}
	}
	if(n!=1)q.push(n);
	if(q.size()==2){
		cout<<2;
		return 0;
	}
	else if(q.size()==1){
		cout<<1<<endl<<0;
		return 0;
	}
	else{
		cout<<1<<endl;
		ans=q.front();
		q.pop();
		cout<<ans*q.front();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100000100
int n,m;
bool v[maxn];
inline void find_prime_numbers(int N){
	for(register int i=2;i*i<=N;i++){
		if(v[i])continue;
		for(register int j=i;j*i<=N;j++){
			v[i*j]=1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	find_prime_numbers(n);
	for(register int i=1;i<=m;i++){
		int a;
		cin>>a;
		if(v[a]){
			cout<<"No";
		}
		else {
			cout<<"Yes";
		}
		cout<<endl;
	}
	return 0;
}

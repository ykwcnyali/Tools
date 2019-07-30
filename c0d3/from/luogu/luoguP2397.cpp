#include<bits/stdc++.h>
using namespace std;
int cnt,mark;
int n,a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>a;
		if(!cnt){
			cnt++;
			mark=a;
		}
		else {
			if(mark!=a){
				cnt--;
			}
			else {
				cnt++;
			}
		}
	}
	cout<<mark;
	return 0;
}

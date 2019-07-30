#include<bits/stdc++.h>
using namespace std;
map <string,string> mapp;
inline string findfa(string x){
	if(mapp[x]!=x)mapp[x]=findfa(x);
	else return x;
}
string pa,s;
char fl;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		cin>>fl;
		cin>>s;
		if(fl=='$')break;
		if(fl=='#'){
			pa=s;
			if(mapp[s]=="")mapp[s]=pa;
		}
		else if(fl=='+'){
			mapp[s]=pa;
		}
		else cout<<s<<" "<<findfa(s)<<endl;
	}
	return 0;
}

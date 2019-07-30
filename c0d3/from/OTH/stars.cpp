#include<iostream>
#include<cmath>
using namespace std; 
#define maxn 15000+10
int n[maxn],N,x[maxn],y; 
int main(){
	ios::sync_with_stdio(0);
    cin>>N; 
    for(register int i=1;i<=N;i++){ 
        cin>>x[i]>>y; 
        int k=0;
        for(register int j=1;j<i;j++){ 
            if(x[j]<=x[i])k++; 
        }
        n[k]++;
    } 
    for(register int i=0;i<N;i++)
		cout<<n[i]<<endl; 
	return 0;
}

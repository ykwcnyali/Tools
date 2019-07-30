#include<iostream>
#include<cstdio>
using namespace std;
int n, t, a[1005], b[1005];
double Jud(double x){
	int i;
	double now = 0;
	for(i=1;i<=n;i++)
	{
		if(b[i]+x<0)
			return t+1;
		now += a[i]/(b[i]+x);
	}
	return now;
}
int main(void){
	int i;
	double l, r, m;
	cin>>n>>t;;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	l = -2000000, r = 2000000;
	while(l+0.0000001<r){
		m = (l+r)/2;
		if(Jud(m)<t)
			r = m;
		else
			l = m;
	}
	printf("%.7f\n", r);
	return 0;
}

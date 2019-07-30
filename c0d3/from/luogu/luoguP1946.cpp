/*================================================================
*   
*   文件名称：luoguP1946.cpp
*   创 建 者：YaliKiWi
*   创建日期：2019年07月19日
*   描    述：
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
#define maxn 20
#define maxx 1000
struct Team{
	int Au;
	int Ag;
	int Cu;
	int tot;
}team[maxn];
struct inequality{
	int quo;
	bool flag;
}ine[maxn];
inline bool cmp(inequality xx,inequality yy){
	return xx.quo<yy.quo;
}
int n;
int ansx=1,ansy=1,ansz=1,ans;
inline void calc(int x,int y){
	for(register int i=1;i<=n;i++){
		team[i].tot=team[i].Au*x+team[i].Ag*y;
	}
}
inline void work(int x,int y){
	calc(x,y);
	int account=0,sum=0;
	for(register int i=2;i<=n;i++){
		int son=team[i].tot-team[1].tot;
		int mum=team[1].Cu-team[i].Cu;
		if(mum==0){
			if(son>=0)sum++;
			continue;
		}
		if(son<0 and mum>0){
			sum++;
			continue;
		}
		if(son>0 and mum<0){
			continue;
		}
		if(mum>0){
			account++;
			ine[account].quo=ceil(son/mum);
			ine[account].flag=1;
		}
		else {
			account++;
			ine[account].quo=floor(son/mum);
			ine[account].flag=0;
			sum++;
		}
	}
	sort(ine+1,ine+account+1,cmp);
	for(register int i=1;i<=account;i++){
		int j=i,cnt=0;
		while(ine[j+1].quo==ine[i+1].quo and j+1<=account){
			j++;
		}
		for(register int k=i;k<=j;k++){
			if(ine[k].flag)sum++;
			else cnt++;
		}
		if(sum>ans and ine[i].quo>0 and ine[i].quo<y){
			ans=sum;
			ansx=x;
			ansy=y;
			ansz=ine[i].quo;
		}
		i=j;
		sum-=cnt;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>team[i].Au>>team[i].Ag>>team[i].Cu;
	}
	for(register int i=1;i<=maxx;i++){
		for(register int j=1;j<=i;j++){
			work(i,j);
		}
	}
	cout<<ansx<<" "<<ansy<<" "<<ansz;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a=0,b=3;
bool used[10000];
#define rep(i,n) for(int i = 0; i<n; i++)
#define endl "\n"
#define pb push_back
int main(){
    freopen("input.txt", "w", stdout);
   	int ans=0;
   	rep(i,1001)ans+=i;
   	cout<<ans;
	mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
	mt 

	/*
	cout<<1000000<<' '<<k<<endl;
	a=rng()%(k+1);
	rep(i,100000-k+1){
		if(rng()%3==0&&a<k)cout<<++a;
		else if(rng()%3==1&&a>0)cout<<--a;
		else cout<<a;
		cout<<' ';
	}
	
	rep(i,19){
		if(i==0)continue;
		cout<<rng()%i+1<<' '<<i+1<<' '<<rng()%5+1<<endl;
	}
	rep(i,11)cout<<rng()%20+1<<' '<<rng()%20+1<<' '<<rng()%5+1<<endl;
	*/
}

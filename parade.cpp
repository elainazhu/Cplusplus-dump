#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,used[200010],dist[200010],x,y,ans,st,tt;
bool d[200020];
vector<ll> adjl[200020];
void dfs(int a,int dista){
	if(d[a])return;
	d[a]=1;
	tt++;
	dist[a]=dista;
	for(auto v: adjl[a]){
			dfs(v, dista+used[v]-2);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n-1; i++){
    	cin>>x>>y;
    	adjl[x].push_back(y);
    	adjl[y].push_back(x);
    	used[x]++;
    	used[y]++;
    }
    for(int i=1; i<=n; i++){
    	if(used[i]>1){
    		st=i;
    		break;
    	}
    }
    //cout<<st<<endl;
    dfs(st,used[st]);
    ll ma=-1;
/*
    for(int i=1; i<=n;i++){
    	cout<<used[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n;i++){
    	cout<<dist[i]<<" ";
    }
    cout<<endl;
*/
    for(int i=1; i<=n;i++){
    	if(dist[i]>ma){
    		ma=dist[i];
    		st=i;
    	}
    }
    memset(d,0,sizeof(d));
    dfs(st,used[st]);
    ma=-1;
    for(int i=1; i<=n;i++) 
    	if(i!=st)
    	ma=max(dist[i],ma);
    /*
    cout<<st<<endl;
    for(int i=1; i<=n;i++){
    	cout<<dist[i]<<" ";
    }
    cout<<endl;
    */
    cout<<ma;
}
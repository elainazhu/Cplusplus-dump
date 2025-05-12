#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll n,e,w,x,y,dist[200020];
bool vis[200010];
vector<ii> adjl[200020];
void longestpath(ll x){
	priority_queue<ii> pq;
	memset(dist,-1,sizeof(dist));
	dist[x]=0;
	pq.push(ii((ll)0,x));
	while(!pq.empty()){
		ll d=pq.top().first;
		ll u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		cout<<u<<" "<<d<<endl;
		for(auto v: adjl[u]){
			if(!vis[v.first]&&d+v.second>dist[v.first]){
				pq.push(ii(d+v.second,v.first));
				dist[v.first]=d+v.second;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>e;
    for(int i=0; i<e; i++){
    	cin>>x>>y>>w;
    	adjl[y].push_back(ii(x,w));
    	adjl[x].push_back(ii(y,w));
    }
    longestpath(1);
    for(int i=1; i<=n; i++){
    	cout<<dist[i]<<" ";
    }
}
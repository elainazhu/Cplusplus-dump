#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
struct node{
	ll x,d,t;
	node(ll _x=0,ll _d=0,ll _t=0):x(_x),d(_d), t(_t){}
};

const int maxn=100010,logn=16;
bitset<maxn> visited;
ll p[logn][maxn],h[maxn],e,x,w,y,dd,tt,gg,q,vv,aa,bb,n,d[maxn];
vector< node > adjl[maxn];
void dfs(int x){
 if(visited[x]) return;
 visited[x]=true;
 for(int i=0; i<logn; i++){
   if(p[i][x]==-1)break;
   p[i+1][x]=p[i][p[i][x]];
 }
 for(auto it:adjl[x]){
   if(visited[it.x])continue;
   p[0][it.x]=x;
   d[it.x]=(d[x]+it.d)%1000000007;
   h[it.x]=h[x]+1;
   dfs(it.x);
 }
}

int lca(int a, int  b){
 if (h[a] > h[b]) swap(a, b);
 for (int k = 0, d = h[b] - h[a]; k < logn; ++k)
   if (d & (1<<k))  b = p[k][b];
 if (a == b) return a;
 for (int k = logn-1; k >= 0; --k)
   if (p[k][a] != p[k][b]) a = p[k][a], b = p[k][b];
 return p[0][a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>gg;
    e=n-1;
	memset(p,-1,sizeof(p));
	for(int i=0; i<e; i++){
	   	cin>>x>>y>>dd>>tt;
	   	adjl[x].push_back(node(y,dd,tt));
	   	adjl[y].push_back(node(x,dd,tt));
	}
	dfs(x);
	cin>>q;
	while(q--){
		cin>>vv>>aa>>bb;
		//printf("%lld %lld %d %lld\n",d[aa],d[bb],lca(aa,bb),d[lca(aa,bb)]);
		cout<<(gg*(d[aa]+d[bb]-2*(d[lca(aa,bb)])))%1000000007;
	}
}
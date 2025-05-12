#include <bits/stdc++.h>
#define int long long
#define pi pair <int, int>
#define ppi pair <pi, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
#define debug(x) cout<<#x<<' '<<x<<endl;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

const int inf = 1000000000000;
int n, m, S, P, scc[500005], a[500005], val[500005], dp[500005];
vector <int> adj[500005], rev[500005], v, condensed[500005];
bool visited[500005], done[500005], pub[500005];

void dfs(int x){
	visited[x] = 1;
	for(int i = 0; i < adj[x].size(); i++) if(!visited[adj[x][i]]) dfs(adj[x][i]);
	v.pb(x); // obtain reverse post-traversal order
}
void dfs2(int x, int p){
	debug(x)
	done[x] = 1;
	scc[x] = p;
	for(int i = 0; i < rev[x].size(); i++)if(!done[rev[x][i]]) dfs2(rev[x][i], p);
} 
//each node x will be in a SCC that starts at scc[x], 
//nodes in the same SCC will have the same scc[x]
int DP(int x){
	if(dp[x] != -1) return dp[x];
	if(condensed[x].size() == 0){
		if(pub[x]) return dp[x] = val[x];
		else return dp[x] = -inf;
	}
	else{
		int tmp;
		for(int i = 0; i < condensed[x].size(); i++){
			int y = condensed[x][i];
			if(i == 0) tmp = DP(y);
			else tmp = max(tmp, DP(y));
		}
		dp[x] = tmp + val[x];
		if(pub[x]) dp[x] = max(dp[x], val[x]);
		return dp[x];
	}
}
signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i <= m; i++){
		cin >> S >> P;
		adj[S].pb(P), rev[P].pb(S);
	}
	for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i);
	while(!v.empty()){
		int x = v.back();
		cout<<x<<endl;
		v.pop_back();
		if(!done[x]) dfs2(x, x);
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		val[scc[i]] += a[i];
		for(int j = 0; j < adj[i].size(); j++){
			if(scc[i] != scc[adj[i][j]]) condensed[scc[i]].pb(scc[adj[i][j]]);
		}
	}
	cin >> S >> P;
	for(int i = 1; i <= P; i++){
		int tmp; cin >> tmp;
		pub[scc[tmp]] = 1;
	}
	cout << DP(scc[S]);
}


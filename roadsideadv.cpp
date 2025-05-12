#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
bool visited[50010];
ll p[20][50010],v,h[50010],w,x,y,q,Q[10],K[10],sum;
ll d[50010],M[10];
vector<ii> adjl[50010];
void dfs(int x){
 if(visited[x]) return;
 visited[x]=true;
 for(int i=0; i<20; i++){
   if(p[i][x]==-1)break;
   p[i+1][x]=p[i][p[i][x]];
 }
 for(auto it:adjl[x]){
   if(visited[it.first])continue;
   p[0][it.first]=x;
   d[it.first]=d[x]+it.second;
   h[it.first]=h[x]+1;
   dfs(it.first);
 }
}

int lca(int a, int  b){
 if (h[a] > h[b]) swap(a, b);
 for (int k = 0, d = h[b] - h[a]; k < 20; ++k)
   if (d & (1<<k))  b = p[k][b];
 if (a == b) return a;
 for (int k = 20-1; k >= 0; --k)
   if (p[k][a] != p[k][b]) a = p[k][a], b = p[k][b];
 return p[0][a];
}
int dist(int a, int b){
	return d[a]+d[b]-d[lca(a,b)];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(p,-1,sizeof(p));
    cin>>v;
    for(int i=0; i<v-1; i++){
	   	cin>>x>>y>>w;
	   	adjl[x].push_back( ii(y,w) );
	   	adjl[y].push_back( ii(x,w) );
	}
	dfs(1);
	cin>>q;
	while(q--){
		sum=0;
		for(int i=0; i<5; i++)cin>>Q[i];
		for(int i=0; i<5; i++){
			for(int j=i+1; j<5; j++){
				sum+=d[Q[i]]+d[Q[j]]-d[lca(Q[i],Q[j])];
				cout<<d[Q[i]]+d[Q[j]]-d[lca(Q[i],Q[j])]<<" ";
				cout<<sum<<endl;
			}
		}
		cout<<endl;
		for(int i=0; i<5; i++){
			for(int j=i+1; j<5; j++){
				for(int k=j+1; k<5; k++){
					sum-=d[Q[i]]+d[Q[j]]+d[Q[k]]-2*d[lca(Q[k],lca(Q[i],Q[j]))];
					cout<<d[Q[i]]+d[Q[j]]+d[Q[k]]-2*d[lca(Q[k],lca(Q[i],Q[j]))]<<" ";
					cout<<sum<<endl;
				}
			}
		}
		cout<<endl;
		for(int i=0; i<5; i++){
			for(int j=i+1; j<5; j++){
				for(int k=j+1; k<5; k++){
					for(int kk=k+1; kk<5; kk++){
						sum+=d[Q[i]]+d[Q[j]]+d[Q[k]]+d[Q[kk]]-3*d[lca(d[Q[kk]],lca(Q[k],lca(Q[i],Q[j])))];
						cout<<d[Q[i]]+d[Q[j]]+d[Q[k]]+d[Q[kk]]-3*d[lca(d[Q[kk]],lca(Q[k],lca(Q[i],Q[j])))]<<" ";
						cout<<sum<<endl;
					}
				}
			}
		}
		cout<<endl;
		sum-=d[Q[1]]+d[Q[2]]+d[Q[3]]+d[Q[4]]+d[Q[5]]-4*d[lca(Q[d[5]],lca(d[Q[4]],lca(Q[3],lca(Q[2],Q[1]))))];
		cout<<sum<<endl;
		cout<<endl;
	}
}
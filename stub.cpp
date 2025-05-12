#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define ll long long
#define ii pair<ll,ll> 
#define iii pair<ll,ii>
#define pb push_back
#define f first
#define s second
#define debug(x) cout<<#x<<' '<<x<<endl;
priority_queue<iii, vector<iii>, greater<iii> > pq;
set<int> s,vt;
vector<int> adj[300010];
ll pa[300010],p[16][300010],d[300010],n,adjpairs,root,p_vt;
int par(int x){return (pa[x]==x) ? x : pa[x]=par(pa[x]);}
void dfs(int x, int P){
  rep(i,15){
    if(p[i][x]==-1)break;
    p[i+1][x]=p[i][p[i][x]];
  }
  for(auto it: adj[x])if(it!=P){
    p[0][it]=x;if(P!=-1)d[x]=d[P]+1;
    dfs(it,x);
  }
}
int lca(int a, int b){
  if(d[a]>d[b])swap(a,b);
  int diff=d[b]-d[a];
  // raise k to the same level
  for(int i=14; i>=0; i--){
    if(diff>=(1<<i)){
      diff-=(1<<i);
      b=p[i][b];
    }
  }
  if(a==b)return a;
  //match upwards
  for(int i=14; i>=0; i--){
    if(p[i][a]!=p[i][b]){
      a=p[i][a];
      b=p[i][b];
    }
  }
  return p[0][a];
}

void init(int N, vector<int> U,vector<int> V, vector<int> W) {
  n=N;
  memset(p,-1,sizeof(p));
  rep(i,N)pa[i]=i;
  rep(i,N-1)if(W[i]==0)pa[par(V[i])]=par(U[i]);
  rep(i,N-1)if(W[i]!=0){
    adj[par(U[i])].pb(par(V[i]));
    adj[par(V[i])].pb(par(U[i]));
  }
  dfs(pa[0],-1);
}

void ins_and_count(int x){
  if(vt.size()<2){
    vt.insert(x);
    adjpairs=1;
  }
  vt.begin()
  root=lca()
  if(x==lca())
  auto it=lower_bound(vt.begin(),vt.end(),x);
}

int flip(int P) {
  if(s.find(P)!=s.end()){
    s.erase(s.find(P));
    auto it = lower_bound(vt.begin(),vt.end(),P)
    if(it==vt.begin()) {
      s.erase(s.find(P));
      return s.size()==vt.size();
    }
    it--;
    int parent=lca(P,)
    // parent= lca(p,*p-1)
    // remove parent if parent not in s && lca(parent, *parent+1) != parent

  }
  else{
    s.insert(P);
    auto it = lower_bound(vt.begin(),vt.end(),P);
    int LCA1=-1,LCA2=-1;
    if(it!=s.end()){

      ins_and_count(lca((*it),P));
    }
    it = lower_bound(vt.begin(),vt.end(),P);
    if(vt.size()&&it!=s.begin()){
      it--;
      int LCA=
      ins_and_count(lca((*it),P));
    }
    ins_and_count(P);
  }
  return s.size()==vt.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  int N, Q;
  assert(1 == scanf("%d", &N));
  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
  }
  init(N, U, V, W);

  assert(1 == scanf("%d", &Q));
  for (int i = 0; i < Q; ++i) {
    int P;
    assert(1 == scanf("%d", &P));
    printf("%d\n", flip(P));
  }
  return 0;
}

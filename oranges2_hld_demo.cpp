#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
using ppl = pair<ll,pl>;
const ll lim = 1e5+5;
ll ufdspar[lim],n,e,q,sz[lim],d[lim],par[lim],head[lim],in[lim],ctr=1;
vector<pl>adjl[lim];

ll findset(ll x){
	if(ufdspar[x]==x)return x;
	else return ufdspar[x]=findset(ufdspar[x]);
}

void mergeset(ll a,ll b){
	a = findset(a), b = findset(b);
	if(a!=b)ufdspar[a]=b;
}

void dfs(ll pos,ll prev){
	sz[pos] = 1;
	for(auto x:adjl[pos]){
		if(x.first==prev)continue;
		d[x.first] = d[pos] + 1;
		par[x.first] = pos;
		dfs(x.first, pos);
		sz[pos] += sz[x.first];
	}
	
	//Remove parent from adjacency list
	for(auto &x:adjl[pos]){
		if(x.first==prev)swap(x,adjl[pos].back());
	}
	if(prev!=-1)adjl[pos].pop_back();
	
	//Make the heavy child the first one in the adjacency list
	for(auto &x:adjl[pos]){
		if(sz[x.first]>sz[adjl[pos][0].first])swap(x,adjl[pos][0]);
	}
}

struct node{
	ll s,e,m,v=0;
	node *l,*r;
	node(ll ss,ll ee){
		s=ss,e=ee,m=(s+e)/2;
		if(s==e)l=r=NULL;
		else l=new node(s,m),r=new node(m+1,e);
	}
	void update(ll p,ll x){
		if(s==e&&s==p)v=x;
		else if(p<=m)l->update(p,x);
		else r->update(p,x);
		if(s!=e)v=max(l->v,r->v);
	}
	ll query(ll a,ll b){
		if(s==a&&e==b)return v;
		else if(b<=m)return l->query(a,b);
		else if(a>m)return r->query(a,b);
		else return max(l->query(a,m),r->query(m+1,b));
	}
}*root;

void dfs2(ll pos){
	in[pos]=ctr++;
	for(auto x:adjl[pos]){
		if(x==adjl[pos][0]){//the heavy child
			head[x.first]=head[pos];
		}
		else{//a light child
			head[x.first]=x.first;
		}
		dfs2(x.first);
		root->update(in[x.first],x.second);
	}
}

ll hld_query(ll a,ll b){
	ll mx=0;
	while(head[a]!=head[b]){//While a and b are not on the same heavy path, we ascend the tree a bit like in LCA
		if(d[head[a]]<d[head[b]])swap(a,b);//Make sure head[a] is deeper to not 'overshoot' the LCA
		
		mx = max(mx, root->query(in[head[a]],in[a]));//Make sure to query in[a] and not a (common bug)
		
		a = par[head[a]];
	}
	if(a!=b){
		if(d[a]<d[b])swap(a,b);	
		mx = max(mx, root->query(in[b]+1,in[a])); //in[b]+1 to not include the edge going from b to its parent (not on the path)
	}
	return mx;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>e>>q;
	vector<ppl>edgelist;
	for(int i=0;i<=n;i++)ufdspar[i]=i;
	for(int i=0;i<e;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		edgelist.emplace_back(w,make_pair(a,b));
	}
	sort(edgelist.begin(),edgelist.end());
	// min spanning tree
	for(auto pp:edgelist){
		ll a,b,w;
		w=pp.first,a=pp.second.first,b=pp.second.second;
		if(findset(a)!=findset(b)){
			mergeset(a,b);
			adjl[a].emplace_back(b,w);
			adjl[b].emplace_back(a,w);
		}
	}
	dfs(0,-1);
	root=new node(0,n+5);
	head[0]=0;
	dfs2(0);
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<hld_query(a,b)<<"\n";
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
const int maxn=300030;
ll v,e,x,y,w,q;
pp ppp,nei;
vector <pp> adjl[maxn];
ll d[maxn],dist[maxn],tresures[maxn],cur,pre[maxn],st,nd;
bool tre[maxn];
void dijkstra(int x){
    memset(dist, 0, sizeof(dist));
    memset(d,0,sizeof(d));
    priority_queue < pp, vector<pp>, greater<pp> > pq;
    pq.push(make_pair(0,x));
    while(pq.size()>0){
        ppp=pq.top();
        pq.pop();
        cur=ppp.second;
        if(d[cur]==1) continue;
        d[cur]=1;
        int nn=adjl[cur].size();
        for(int i=0; i<nn; i++){
            nei= adjl[cur][i];
            if(d[nei.first]==0&&(dist[nei.first]>ppp.first+nei.second||dist[nei.first]==0)){
                pq.push(make_pair(ppp.first + nei.second, nei.first));
                dist[nei.first]=ppp.first+nei.second;
            }
        }
    }
}
void dij(int x){
    memset(dist, 0, sizeof(dist));
    memset(d,0,sizeof(d));
    priority_queue < pp, vector<pp>, greater<pp> > pq;
    pq.push(make_pair(0,x));
    while(pq.size()>0){
        ppp=pq.top();
        pq.pop();
        cur=ppp.second;
        if(d[cur]==1) continue;
        d[cur]=1;
        int nn=adjl[cur].size();
        for(int i=0; i<nn; i++){
            nei= adjl[cur][i];
            if(d[nei.first]==0&&(dist[nei.first]>ppp.first+nei.second||dist[nei.first]==0)){
                pq.push(make_pair(ppp.first + nei.second, nei.first));
                dist[nei.first]=ppp.first+nei.second;
                tresures[nei.first]=tresures[cur]+tre[cur];
                pre[nei.first]=cur;
            }
            if(dist[nei.first]==ppp.first+nei.second && tresures[cur]+tre[cur]>tresures[nei.first] ){
                pq.push(make_pair(ppp.first + nei.second, nei.first));
                dist[nei.first]=ppp.first+nei.second;
                tresures[nei.first]=tresures[cur]+tre[cur];
                pre[nei.first]=cur;
            }
        }
    }
    ll ma=0;
    for(ll i=1; i<=v; i++){
    	if(tre[i]){
    		if(dist[i]>ma){
    			nd=i;
    			ma=dist[i];
    		}
    	}
    }
    ll ennd=nd;
    ll num=1;
    while(ennd!=st){
    	num++;
    	ennd=pre[ennd];
    }
    cout<<num<<endl;
    while(nd!=st){
    	cout<<nd<<" ";
    	nd=pre[nd];
    }
    cout<<st;
}
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>v>>e;
    for(int i=0; i<e; i++){
        cin>>x>>y>>w;
        adjl[x].push_back(make_pair(y,w));
        adjl[y].push_back(make_pair(x,w));
    }
    cin>>q;
    for(int i=0; i<q; i++){
    	cin>>x;
    	tre[x]=true;
    }
    dijkstra(x);
    ll ma=0;
    for(ll i=1; i<=v; i++){
    	if(tre[i]){
    		if(dist[i]>ma){
    			st=i;
    			ma=dist[i];
    		}
    	}
    }
    dij(st);
}

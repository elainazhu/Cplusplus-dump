#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll n,g[200010],e,ttl;
int k;
priority_queue<ii> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>g[i];
    }
    int id=0;
    for(int i=0; i<n; i++){
        cin>>e;
        id=max(id,i-k);
        int cur=0;
        while(id<=i&&g[id]<e-cur){
            cur+=g[id];
            id++;
        }
        if(id<=i){
            int temp=min(e-cur, g[id]);
            g[id]-=temp;
            cur+=temp;
        }
        ttl+=cur;
        //cout<<cur;
    }
    cout<<ttl;
}
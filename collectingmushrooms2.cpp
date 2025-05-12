#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii ma(ii a, ii b){ return a.first>=b.first ? a:b;}
struct node {
     int s, e;
     ii v;
     node * l, * r;
     node(int ss, int ee) {
         s = ss;
         e = ee;
         if (s == e) l = r = NULL;
         else {
             l = new node(s, (s + e) / 2);
             r = new node((s + e) / 2 + 1, e);
         }
     }
     void set(int p, ii nv) {
         if (s == e) {
             v = nv;
             return;
         }
         if (p <= (s + e) / 2) l -> set(p, nv);
         else r -> set(p, nv);
         v = ma(l -> v, r -> v);
     }
     ii query_max(int a, int b) {
         if (a <= s && e <= b) return v;
         ii ans = ii(INT_MIN,0);
         if (a <= (s + e) / 2) ans = l -> query_max(a, b);
         if ((s + e) / 2 < b) return ma(ans, r -> query_max(a, b));
         return ans;
     }
 }* root;
 ll n,q,k,a,b,v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>q;
    root = new node(0, 210000);
    for(int i=0; i<n; i++){
        cin>>v;
        root->set(i,make_pair(v,i));
    }
    while(q--){
        cin>>a>>b;
        ii vv=root->query_max(a,b);
        cout<<vv.first<<endl;
        root->set(vv.second, make_pair(-1,vv.second));
    }
}

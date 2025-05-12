#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii ma(ii a, ii b){ return a.first>=b.first ? a:b;}
struct node {
    int s, e;
    ii mx;
    bool lset;
    ii set_val;
    node *l, *r;
    node (int _s, int _e, ii A[] = NULL): s(_s), e(_e), mx(ii(0,0)), lset(0), set_val(ii(0,0)), l(NULL), r(NULL) {
        if (A == NULL) return;
        if (s == e) mx = A[s];
        else {
            l = new node(s, (s+e)>>1, A), r = new node((s+e+2)>>1, e, A);
            if(l!=NULL)mx = ma(l->mx, r->mx);
        }
    }
    void self_set(ii v) {
        lset = 1;
        mx = set_val = v;
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        int m = (s+e)>>1;
        l = new node(s, m);
        r = new node(m+1, e);
    }
    void lazy_propagate() {
        if (s == e) return;
        if (lset) {
            l->self_set(set_val), r->self_set(set_val);
            lset =0;
            set_val = ii(0,0);
        } 
    }
    void set(int x, ii v) {
        if (s == x && e == x) { 
        	lset = 1;
	        mx = set_val = v;
    	}
        int m = (s+e)>>1;
        create_children();
        if (x <= m) l->set(x, v);
        else r->set(x, v);
        if (l != NULL) mx = ma(l->mx, r->mx);
    }
    ii range_ma(int x, int y) {
        if (s == x && e == y) return mx;
        if (l == NULL || lset) return mx; //node not created or end node
        int m = (s+e)>>1;
        lazy_propagate();
        if (y <= m) return l->range_ma(x, y);
        if (x > m) return r->range_ma(x, y);
        return ma(l->range_ma(x, m), r->range_ma(m+1, y));
    }
    ~node() {
        if (l != NULL) delete l;
        if (r != NULL) delete r;
    }
} *root;


ll n,q,k,a,b,v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>q;
		cout<<0;
		fflush(stdout);
	root = new node(0, 1100000000);
		cout<<1;
		fflush(stdout);
	for(int i=0; i<n; i++){
		cin>>v;
		cout<<i;
		fflush(stdout);
		root->set(i,make_pair(v,i));
	}
    while(q--){
    	cin>>a>>b;
    	ii vv=root->range_ma(a,b);
    	cout<<vv.first;
    	root->set(vv.second, make_pair(-1,vv.second));
    }
}


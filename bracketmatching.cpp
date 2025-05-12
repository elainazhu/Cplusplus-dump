#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int n;
char s[100010];
stack<char> st;
struct AugPath {
    int A, B;   //size of left, right groups
    vector< vector<ii> > G; //size A
    vector<bool> visited;   //size A
    vector<ii> P;          //size B

    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, ii(-1,0)) {}
    void AddEdge(int a, int b, int c) {    //a from left, b from right
        G[a].push_back(ii(b,c));
    }
    int Aug(int x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        ll curmx=0,kek;
        for (auto it:G[x]) {
            if(P[it.first].first == -1) {
            	if(it.second>curmx){
                	kek = it.first;
                	curmx=max(it.second,curmx);
            	}
            }
        }
        for (auto it:G[x]) {
        	int xxx=Aug(P[it.first].first);
            if (xxx>0){
				if(it.second>curmx){
                	kek = it.first;
                	curmx=max(it.second,curmx+xxx-P[it.first].second);
            	}
            }
        }
        return curmx;
    }
    // keep pre[]?
    // then traceback and assign P
    ii MCBM() {
        int matchings = 0,ttl=0;
        for (int i = 0; i < A; ++i) {
            visited.resize(A, 0);
            int curr=Aug(i);
            ttl+=curr;
            if(curr>0)matchings++;
            visited.clear();
        }
        return ii(matchings, ttl);
    }
} *root;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int tt,pp,cc,w,x,y;
	cin>>tt>>pp>>cc;
	root=new AugPath(pp,tt);
	for(int i=0; i<cc; i++){
		cin>>x>>y>>w;
		root->AddEdge(x-1,y-1,w);
	}
	ii ans;
	ans=root->MCBM();
	cout<<tt-ans.first<<" "<<ans.second;
	return 0;
}
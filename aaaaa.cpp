#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1; i<=n; i++)
#define pb push_back
#define int long long
#define ii pair<int,int>
#define f first
#define s second
int n,M,Q;
struct node{
    int s,e,m,v,lazy;
    node *l,*r;
    node(int S, int E){
        s=S,e=E,m=(s+e)/2;
        v=0;lazy=0;
        if(s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    void prop(){
        if(lazy==0)return;
        v=v+lazy;
        if(s!=e){
            l->lazy+=lazy;
            r->lazy+=lazy;
        }
        lazy=0;
    }
    void upd(int S, int E, int V){
        if(s==S && e==E){
            if(pos!=-1){
                lazy+=lca(pos,V);
                lazy-=inv[pos];
                lazy+=inv[V];
            }
            else{
                l->upd(S,m,V);
                r->upd(m+1,E,V);
            }
            pos=V;
        }
        else{
            if(E<=m)l->upd(S,E,V);
            else if(S>m)r->upd(S,E,V);
            else{
                l->upd(S,m,V);
                r->upd(m+1,E,V);
            }
            l->prop();r->prop();
            if(l->pos==r->pos)pos=l->pos;
            else pos=-1;
        }
        //cout<<s<<' '<<e<<' '<<S<<' '<<E<<' '<<pos<<endl;
    }
    int qry(int S){
        prop();
        if(s==S&&e==S)return v-inv[pos];
        if(S<=m)return l->qry(S);
        else return r->qry(S);
    }
}*root;
signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    root=new node(1, M);
    dfs(1,-1);
    rep(i,Q){
        char ch;cin>>ch;
        if(ch=='q'){
            int a; cin>>a;
            cout<<-root->qry(a)<<endl;

        }else if(ch=='e'){
            int a,val;
            cin>>a>>val;
            inv[a]+=val;
        }else{
            int l,r,a;
            cin>>l>>r>>a;
            root->upd(l,r,a);
        }
    }
}
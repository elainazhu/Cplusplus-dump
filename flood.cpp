#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1; i<=n; i++)
#define pb push_back
#define ii pair<int,int>
#define dii pair<double, ii>
#define f first
#define s second

int n,found,queries,queriess,a[1010],brute;
int query(int l, int r){
    //cout<<l<<' '<<r<<endl;
    //cout<<a[r]-a[l-1]<<endl;
    return a[r]-a[l-1];
}
int queryy(int l, int r){
    cout<<"? "<<l<<' '<<r<<endl;
    int ret;
    cin>>ret;
    return ret;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
void findd(int s, int e, double v){
    int m=(s+e)/2;
    if(s==e){
        if(v==1){
            found=s;
        }
        return;
    }
    if(found)return;
    double vv=query(s,m);
    queries++;
    if(vv/(m+1-s)<(v-vv)/(e-m)){
        findd(s,m,vv);
        findd(m+1,e,v-vv);
    }else{
        findd(m+1,e,v-vv);
        findd(s,m,vv);
    }
}

void finddd(int s, int e, double v){
    priority_queue<dii, vector<dii>, greater<dii> > pq;
    pq.push({v,{s,e}});
    while(!found&&pq.size()){
        int s=pq.top().s.f,e=pq.top().s.s;
        int m=(s+e)/2;
        double vv=query(s,m),v=pq.top().f*(e-s+1);
    queriess++;
        pq.pop();
        if(s==m&&vv==1){
            found=s;
            return;
        }if(m+1==e&&abs(v-vv-1)<0.1){
            found=e;
            return;
        }
        if(s!=m)pq.push({vv/(m+1-s),{s,m}});
        if(e!=m+1)pq.push({(v-vv)/(e-m),{m+1,e}});
    }
}
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
signed main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    rep(i,1000){
        vector<int> v;
        rep(j,1000){
            v.pb(j);
        }
        shuffle(v.begin(), v.end(),rng);
        rep(i,1000)a[i]=v[i-1]+a[i-1];
        findd(1,1000,500500);
        found=0;
        finddd(1,1000,500500);
        brute+=found;
        found=0;
    }
    cout<<queriess<<endl<<queries<<endl<<brute;
    
}

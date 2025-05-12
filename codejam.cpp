#include<bits/stdc++.h>
#include <string>
using namespace std;
#define pb push_back
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define rep(i,n) for(int i=0; i<n; i++)
#include <math.h>
int T,n;
pair<int, ii> a[200010];
int aa[200010];
bool cmp(pair<int, ii> x, pair<int, ii> y){
    if(x.f>y.f)return true;
    if(x.f<y.f)return false;

    if(x.s.s> y.s.s) return true;
    if(x.s.s< y.s.s) return false;
    if(x.s.f> y.s.f)return true;

    return false;
}
bool cmpp(pair<int, ii> x, pair<int, ii> y){
    if(x.s.f> y.s.f)return true;
    if(x.s.f< y.s.f)return false;

    if(x.s.s> y.s.s) return true;
    if(x.s.s< y.s.s) return false;

    if(x.f>y.f)return true;
    return false;
}
signed main(){
    freopen("input.txt", "r", stdin);
    cin>>T;
    while(T--){
        cin>>n;
        rep(i,n){
            cin>>aa[i];
        }
        rep(i,n-2){
            a[i]={aa[i],{aa[i+1],aa[i+2]}};
        }
        sort(a, a+n);
        int ans=0,cnt=0,curcnt=0;
        for(int i=1; i<n; i++){
            int a1=a[i].f,a2=a[i].s.f, a3=a[i].s.s;
            int b1=a[i-1].f,b2=a[i-1].s.f, b3=a[i-1].s.s;
            curcnt++;
            cnt++;
            if(a1!=b1 or a2!=b2){
                ans-=(curcnt*(curcnt-1))/2;
                ans+=(cnt*(cnt-1))/2;
                curcnt=0;
                cnt=0;
            }
            if(a3!=b3){
                ans-=(curcnt*(curcnt-1))/2;
                curcnt=0;
            }

        }
        sort(a, a+n,cmp);
        cnt=0,curcnt=0;
        for(int i=1; i<n; i++){
            int a1=a[i].f,a2=a[i].s.f, a3=a[i].s.s;
            int b1=a[i-1].f,b2=a[i-1].s.f, b3=a[i-1].s.s;
            curcnt++;
            cnt++;
            if(a1!=b1 or a3!=b3){
                ans-=(curcnt*(curcnt-1))/2;
                ans+=(cnt*(cnt-1))/2;
                curcnt=0;
                cnt=0;
            }
            if(a2!=b2){
                ans-=(curcnt*(curcnt-1))/2;
                curcnt=0;
            }

        }
        sort(a, a+n,cmpp);
        cnt=0,curcnt=0;
        for(int i=1; i<n; i++){
            int a1=a[i].f,a2=a[i].s.f, a3=a[i].s.s;
            int b1=a[i-1].f,b2=a[i-1].s.f, b3=a[i-1].s.s;
            curcnt++;
            cnt++;
            if(a2!=b2 or a3!=b3){
                ans-=(curcnt*(curcnt-1))/2;
                ans+=(cnt*(cnt-1))/2;
                curcnt=0;
                cnt=0;
            }
            if(a1!=b1){
                ans-=(curcnt*(curcnt-1))/2;
                curcnt=0;
            }
        }
        cout<<ans<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int n,a[100010],k;
bool check(int x){
    int cur=0,sum=0;
    for(int i=0; i<n; i++){
        if(cur+a[i]>x){
            sum++;
            cur=0;
        }
        cur+=a[i];
    }
    sum++;
    //cout<<x<<" "<<sum<<endl;
    return sum>k;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;
    int ss=0;
    for(int i=0; i<n; i++){
    	cin>>a[i];
        ss+=a[i];
    }
    int s=0, e=ss, mid;
    while(mid=(e+s)/2, e-s>1){
        if(check(mid)) s=mid;
        else e=mid;
    }
    cout<<e;
}
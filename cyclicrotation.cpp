#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>t;
    while(t--){
    	int a[200010],b[200010],n,cnt[200010];
    	memset(cnt,0,sizeof(cnt));
    	cin>>n;
    	for(int i=0; i<n; i++)cin>>a[i];
    	for(int i=0; i<n; i++)cin>>b[i];
    	int j=0;
    	for(int i=0; i<n; i++){
    		if(a[i]==b[j]){
    			j++;
    			while(a[i]==b[j]&&cnt[a[i]]>0)j++,cnt[a[i]]--;
    		}else cnt[a[i]]++;
    	}
    	cout<<(j==n ? "YES":"NO")<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
//get<0>(v[i])
ll n,k,a[3010],b[3010],id[3010];
iii h[3010];
vector<ii> v;
//end,start
bool cmp(int x, int y){
	return a[x]<a[y];
}
int longest(int x,int y){
	int i=0;
	int j=0;
	printf("starting with %d:\n",x);
	while(i<n-1&&j<k){
		while(i<n-1&&h[i].second.first<x&&h[i].second. second<=y)i++;
		if((h[i].second.first<x||h[i].second.second<=y)){i++;continue;}
		x=h[i].first;
		j++;
		cout<<h[i].first<<" "<<h[i].second.first<<" "<<h[i].second.second+1<<endl;
	}
	cout<<j<<endl<<endl;
	return j;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;
    for(int i=0; i<n; i++){
    	cin>>h[i].second.first>>h[i].first;
    	h[i].second.second=i;
    	a[i]=h[i].second.first;
    	b[i]=h[i].first;
    	id[i]=i;
    }
    sort(h, h+n);
    sort(id,id+n,cmp);
    if(longest(0,0)<k){
    	cout<<-1;
    	return 0;
    }
    for(int i=0; i<n; i++){ 
    	//if(v.size()>0)cout<<a[id[i]]<<" "<<v[v.size()-1].second<<endl;
    	printf("for %d:\n",i+1);
    	if((v.size()==0||a[id[i]]>=v[v.size()-1].second)&&longest(b[id[i]],id[i])>k-v.size()-1){
    		v.push_back(ii(i,b[id[i]]));
    	}
    }
    for(auto it: v){
    	cout<<it.first+1<<endl;
    }
}
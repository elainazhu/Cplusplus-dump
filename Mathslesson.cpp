#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll t[1000010], d[1000010], n, id[1000010],sum,maxsum,ttt;
priority_queue<ll, vector<ll>, greater<ll> > pq;
bool cmp(int x,int y){
	return t[x]<t[y];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++){
    	cin>>t[i];
    	cin>>d[i];
    	id[i]=i;
    }
    sort(id,id+n,cmp);
    for(int i=0; i<n; i++){
    	int temp=0;
    	while(pq.size()!=0&&pq.top()<=t[id[i]]){
    		sum-=pq.top()-t[id[i-1]];
    		pq.pop();
    	}
    	int tt=t[id[i]];
    	if(i>0){
    		tt=t[id[i]]-t[id[i-1]];
    	}
    	pq.push(t[id[i]]+d[id[i]]);
    	sum+=tt+d[id[i]];
    	sum-=pq.size()*tt;
    	temp+=pq.size()*tt;
    	if(sum>maxsum){
    		maxsum=sum;
    		ttt=t[id[i]];
    	}
    	//cout<<sum<<" "<<temp<<" "<<tt<<endl;
    }
    cout<<ttt;
}
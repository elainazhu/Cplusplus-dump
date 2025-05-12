#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll q, n, l,t,r,x;
char S[1000000];
set<int> s;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>q;
    cin>>S;
    for(int i=0; i<n; i++){
    	if(i==0||S[i-1]!=S[i])s.insert(i);
    }
    while(q--){
    	cin>>t>>l>>r,l--,r--;
    	if(t==1){
    		if(s.count(l))s.erase(l);
    		else s.insert(l);
    		if(s.count(r+1))s.erase(r+1);
    		else if(r+1<n)s.insert(r+1);
    	}else{
    		cin>>x,x--;
    		auto it=lower_bound(s.begin(), s.end(), l);
    		int yeet=1;
    		//cout<<*it<<" ";
    		auto itt=s.end();
    		itt--;
            /*
            if(it==s.end()){
                if(x==l)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                break;
            }
            */
    		while(it!=s.end()&&*it!=*itt&&*it<r&&yeet<3){
    			yeet++;
    			it=next(it);
    			//cout<<*it<<" ";
    		}
    		//cout<<endl;
    		//cout<<yeet<<endl;
            //cout<<*it<<x;
    		if(yeet==3||(yeet==2&&(*it)==x)||(yeet==1&&x==l))cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    	}
    }
}
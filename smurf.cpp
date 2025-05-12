#include<bits/stdc++.h>
using namespace std;
int n, a;
deque<int> d;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++){
    	cin>>a;
    	if(i%2)d.push_front(a);
    	else d.push_back(a);
    }
    if(n%2){
    	while(!d.empty()){
    		n--;
	    	cout<<d[n]<<" ";
	    	d.pop_back();
	    }
    }else
    while(!d.empty()){
    	cout<<d[0]<<" ";
    	d.pop_front();
    }

}
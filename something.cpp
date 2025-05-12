#include <bits/stdc++.h> 
#include <math.h> 
using namespace std;
typedef pair<int,int> pii;
int n,e,s,d,a,b,t,height[100010], indx[100010], curindex,dist[100010],dd[100010];
bool flagg,visited[100010],isloop[100010],loopexists;
vector<pii> adjl[100010];
stack<int> ss;
void dfs(int x){
	if(visited[x])return;
	visited[x]=true;
	for(auto it : adjl[x]){
		dfs(it.first);
	}
}
void dfss(int x){
	indx[x] = curindex;
	height[x] = curindex;
	curindex++;
	ss.push(x);
	visited[x] = true;
	for(auto it:adjl[x]){
		if(indx[it.first]==0){
			dfss(it.first);
			height[x] = min(height[x], height[it.first]);
		}
		else if(visited[it.first]){
			height[x] = min(height[x], indx[it.first]);
		}
	}
	if(indx[x]==height[x]){
		bool isl = false,nya=false;
		while(ss.top()!=x){
			isloop[ss.top()]=true;
			isl = true;
			visited[ss.top()] = false;
			ss.pop();
		}
		isloop[ss.top()] = isl;
		visited[ss.top()] = false;
		ss.pop();
	}
}
bool findloop(int x, bool hasloop){
	if(isloop[x]) hasloop=true;
	if(x==d){ return hasloop;}
	if(visited[x]) return false;
	visited[x]=true;
	bool ans = false;
	
	for(auto it: adjl[x]){
		if(findloop(it.first, hasloop)) ans = true;
	}
	return ans;
}
void dfsss(int x,int dis){
	//cout<<x<<endl;
	for(auto it: adjl[x]){
		if(dist[it.first]<dis+it.second&&!isloop[it.first]){
			dist[it.first]=dis+it.second;
			dfsss(it.first,dis+it.second);
		}
	}
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>e>>s>>d;
	for(int i=0; i<e; i++){
		cin>>a>>b>>t;
		adjl[a].push_back(pii(b,t));
	}
	dfs(s);
	if(!visited[d]){
		cout<<-1;
		return 0;
	}
	memset(visited, 0, sizeof(visited));
	dfss(s);
	memset(visited, 0, sizeof(visited));
	//	for(int i=0; i<n; i++){if(isloop[i])printf(", %d, ", i);}
	if(findloop(s,false)){
		cout<<-2;
		return 0;
	}
	dfsss(s,0);
	cout<<dist[d];

}

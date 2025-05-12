
#include<bits/stdc++.h>
using namespace std;
typedef double ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ii> iii;
long long n,q,a,b;
// pair(gradient, (start,end));
set<ii> gradient;
set<ii> intpoints;
//pair (intersection points, y value)
//find minimum → use set<int, greater>;
ii intersection(ll m1, ll c1, ll m2, ll c2){
	ll x = (c1-c2)/(m2-m1);
	return ii(x, m1*x+c1);
}
void addline(ll m, ll c){
	ll start, end;
	auto it = lower_bound(gradient.begin(),gradient.end(), ii(m, -1e9));
	auto l = it;
	auto r = it;
	if(it==gradient.end()){ // no greater gradient, it past last line 
		it--; // last line
		intpoints.insert(intersection(m, c, (*it).first, (*it).second));
		gradient.insert(ii(m, c));
		return;
	}
	if(it == gradient.begin()){
		if((*it).first==m){ // case1: same gradient
			if((*it).second > c){
			return;
		}
		// remove intersection point of the previous stuff
		r = it;
		r++;
		intpoints.erase(intpoints.find(intersection((*r).first, (*r).second, (*it).first, (*it).second)));
		// remove prev line
		gradient.erase(it);
		}

		intpoints.insert(intersection(m, c, (*it).first, (*it).second));
		gradient.insert(ii(m, c));
		return;
	}
	if((*it).first == m){ 
		if((*it).second > c){
			return;
		}
		l = it;
		l--;
		r = it;
		r++;
		intpoints.erase(intpoints.find(intersection((*l).first, (*l).second, (*it).first, (*it).second)));
		if(r!=gradient.end()) intpoints.erase(intpoints.find(intersection((*r).first, (*r).second, (*it).first, (*it).second)));
		gradient.erase(it);
		it = r;
	}else{
		l = it;
		l--;
		r = it;
	}
	if(it==gradient.end()){
		it--;
		intpoints.insert(intersection(m, c, (*it).first, (*it).second));
		gradient.insert(ii(m, c));
		return;
	}
		while(true){
			it = l;
			if(l==gradient.begin()) break;
			l--;
			if(intersection((*l).first, (*l).second, (*it).first, (*it).second)<intersection((*l).first, (*l).second, m, c)){
				l = it;
				break;
			}
			intpoints.erase(intpoints.find(intersection((*l).first, (*l).second, (*it).first, (*it).second)));
			gradient.erase(it);
		}
		while(true){
			it = r;
			r++;
			if(r==gradient.end()){
				r--;
				break;
			}
			if(intersection((*r).first, (*r).second, (*it).first, (*it).second)>intersection((*r).first, (*r).second, m, c)){
				r = it;
				break;
			}
			intpoints.erase(intpoints.find(intersection((*r).first, (*r).second, (*it).first, (*it).second)));
			gradient.erase(it);
		}
		intpoints.insert(intersection((*r).first, (*r).second, m, c));
		intpoints.insert(intersection((*l).first, (*l).second, m, c));
		gradient.insert(ii(m,c));

}
ll findval(ll x){
	auto it = lower_bound(intpoints.begin(), intpoints.end(), ii(x, -1e9));
	if(it==intpoints.begin()){
		return (*(gradient.begin())).first*x + (*(gradient.begin())).second;
	}
	if(it==intpoints.end()){
		return (*(gradient.rbegin())).first*x + (*(gradient.rbegin())).second;
	}
	ll xx = it->first, yy = it->second;
	it--;
	return ((yy-(*it).second)/(xx-it->first))*(x-it->first)+it->second;
}
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld%lld", &n,&q);
    scanf("%lld%lld", &a, &b);
    gradient.insert(ii(a,b));
    for(int i=1; i<n; i++){
    	scanf("%lld%lld",&a,&b);
    	addline(a,b);
    }
    for(int i=0; i<q; i++){
    	scanf("%lld",&a);
    	printf("%.0lf\n",findval(a));
    }
}
/*4 5
1 2
0 3
-1 6
1 0
1 3 5 7 9*/


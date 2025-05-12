#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300010;
ll t, n, a[maxn][2], dp[maxn][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--){
    	scanf("%lld", &n);
        a[0][0]=1e16;
    	for(int i=1; i<=n; i++){
    		scanf("%lld%lld", &a[i][0], &a[i][1]);
    	}
        //min(dp(n-1, x) given A[i-1] + x =/= A[i] + k)
    	for(int i=1; i<=n; i++){
            for(int k=0; k<=2; k++){
                dp[i][k]=1e15;
        		for(int j=0; j<=2; j++){
                    if(a[i-1][0]+j!=a[i][0]+k)
                        dp[i][k]=min(dp[i-1][j]+k*a[i][1],dp[i][k]);
                    //cout<<"("<<a[i-1][0]+j<<","<<a[i][0]+k<<","<<dp[i-1][j]+j*a[i-1][1]<<","<<dp[i][k]<<") ";
                }
                //cout<<endl;
            }
            //cout<<endl;
    	}
        printf("%lld\n", min(dp[n][0],min(dp[n][1],dp[n][2])));
    }
}
//https://codeforces.com/contest/1221/problem/D
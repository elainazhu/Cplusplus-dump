#include<bits/stdc++.h>
#include <string>
using namespace std;
int n,a,dp0[5010][2],dp1[5010][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<=n/2; i++){
        dp0[i][0]=dp0[i][1]=dp1[i][0]=dp1[i][1]=1000000000;
    }
    dp0[0][0]=0;
    dp0[1][1]=0;
    for(int i=1; i<n; i++){
        cin>>a;
        for(int i=0; i<=n/2; i++){
            dp1[i][0]=dp1[i][1]=1000000000;
        }
        for(int j=0; j<=n/2; j++){
            dp1[j][0]=min(dp0[j][0],dp0[j][1]+a);
            if(j>1)
                dp1[j][1]=min(dp0[j-1][1],dp0[j-1][0]+a);
            //cout<<dp1[j][0]<<"|"<<dp1[j][1]<<", ";
        }
        swap(dp0,dp1);
        //cout<<endl;
    }
    cout<<min(dp0[n/2][0],dp0[n/2][1]);
}
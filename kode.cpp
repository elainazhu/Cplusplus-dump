 8 void solve() {
  9         int n; cin >> n;
 10         int A[n], dp[n][2];
 11         set<int> s;
 12         for(int i=0; i<n; ++i){
 13                 cin >> A[i];
 14                 if(i == 0){
 15                         dp[0][0] = 1;
 16                         dp[0][1] = 0;
 17                 } else {
 18                         dp[i][0] = max(0,dp[i-1][0] + score(A[i], dp[i-1][0])); // don't skip
 19                         dp[i][1] = max(1,dp[i-1][1] + score(A[i], dp[i-1][1]));
 20 //                      for(int j=0; j<i-1; ++j){
 21 //                              dp[i][1] = max(dp[i][1], dp[j][0] + score(A[i], dp[j][0])); // don't skip up to <=j
 22 //                      }
 23                         auto it = s.lower_bound(A[i]);
 24 //                      printf("finding %d\n", *it);
 25                         if(!s.empty() and it != s.begin()) dp[i][1] = max(dp[i][1], score(A[i], *prev(it)) + *prev(it));
 26                         s.insert(dp[i-1][0]);
 27                 }
 28 //              printf("dp[%d] = %d %d\n", i, dp[i][0], dp[i][1]);
 29         }
 30         int ans = dp[n-1][1];
 31         if(!s.empty()) ans = max(ans, *--s.end());
 32         cout << ans << "\n";
 33 }
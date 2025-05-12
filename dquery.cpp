#include<bits/stdc++.h>
#include <cmath>
using namespace std;

unordered_map<long long, int> memo;

int dp(long long n) {
    if (n == 0) return 0;
    if (memo.count(n)) return memo[n];

    int res = INT_MAX;
    for (int i = 0; i < 60; ++i) {
        long long pow2 = 1LL << i;
        if (n >= pow2) {
            res = min(res, 1 + dp(n - pow2));  // Subtracting 2^i
        }
        res = min(res, 1 + dp(n + pow2));      // Adding 2^i (safe, will eventually reduce)
        if (pow2 > n * 2) break;               // No need to check very large powers
    }

    return memo[n] = res;
}

int getMinOperations(long long n) {
    memo.clear(); // Clear memoization map between test cases
    return dp(n);
}

int32_t main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    vector<long long> test_cases = {647335, 7, 21, 27, 998647};
    for (long long n : test_cases) {
        cout << "n = " << n << ", min operations = " << getMinOperations(n) << endl;
    }

    return 0;
}
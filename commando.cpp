#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200010;
int n, m, b, a[N];

// Function to check if we can partition the cake into `m + 1` pieces
// where each of the `m` creatures' pieces has tastiness >= `b`.
bool check(int minTastiness) {
    int curSum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        curSum += a[i];
        if (curSum >= minTastiness) {
            count++;
            curSum = 0; // Reset current sum for the next piece
            if (count >= m) return true; // If we made `m` pieces, we're good
        }
    }
    return false; // Not enough pieces with tastiness >= `minTastiness`
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        cin >> n >> m >> b;
        for (int i = 0; i < n; i++) cin >> a[i];

        // Binary search for the maximum tastiness Alice can get
        int left = 0, right = accumulate(a, a + n, 0LL), result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                result = mid;
                left = mid + 1; // Try for a larger tastiness
            } else {
                right = mid - 1; // Reduce tastiness
            }
        }

        cout << result << '\n';
    }
    return 0;
}

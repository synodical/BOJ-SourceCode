#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 105;
int n,t;
ll dp[MAX];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for (int i = 4; i <= 102; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}



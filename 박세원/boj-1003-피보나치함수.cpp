#include <iostream>
#define MAX_N 41

using namespace std;

int T, N, dp[MAX_N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < MAX_N; ++i) {
        dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }

    while (T--) {
        cin >> N;

        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }

    return 0;
}
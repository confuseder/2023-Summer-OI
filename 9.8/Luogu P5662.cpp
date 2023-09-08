#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int price[105][105];
int dp[10005];

int main() {

    // freopen("Luogu P5662.in", "r", stdin);
    // freopen("Luogu P5662.out", "w", stdout);

    cin >> t >> n >> m;

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[i][j];
        }
    }

    for (int d = 1; d < t; d++) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = price[d][i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - price[d][i]] + price[d + 1][i] - price[d][i]);
            }
        }
        m += dp[m];
    }

    cout << m << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
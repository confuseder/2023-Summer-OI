#include <bits/stdc++.h>
using namespace std;

int n, m, S;
int v[1005][1005], w[1005][1005];
int dp[3][1005][705];

int main() {

    // freopen("thief.in", "r", stdin);
    // freopen("thief.out", "w", stdout);

    cin >> n >> m >> S;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = v[i][j]; k <= S; k++) {
                dp[2][j][k] = max(dp[2][j][k], dp[1][j][k]);
                dp[2][j][k] = max(dp[2][j][k], dp[2][j - 1][k]);

                dp[2][j][k] = max(dp[2][j][k], dp[1][j][k - v[i][j]] + w[i][j]);
                dp[2][j][k] =
                    max(dp[2][j][k], dp[2][j - 1][k - v[i][j]] + w[i][j]);
            }
            for (int k = 0; k <= v[i][j]; k++) {
                dp[2][j][k] = max(dp[2][j][k], dp[1][j][k]);
                dp[2][j][k] = max(dp[2][j][k], dp[2][j - 1][k]);
            }
        }
        memcpy(dp[1], dp[2], sizeof(dp[2]));
        memset(dp[2], 0, sizeof(dp[2]));
    }

    cout << dp[1][m][S] << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
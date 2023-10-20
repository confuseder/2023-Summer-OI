#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;

int n, m;
int dp[1005][1005];

int main() {

    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= 2 * m; i++) {
        dp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 2 * m; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % Mod;
        }
    }

    cout << dp[m * 2][n] << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
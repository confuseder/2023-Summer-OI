#include <bits/stdc++.h>
using namespace std;

int n, tot, ans;
int num[105];
bool dp[105][200005];

int main() {

    // freopen("Luogu P8742.in", "r", stdin);
    // freopen("Luogu P8742.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        tot += num[i];
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tot; j++) {
            dp[i][j] = dp[i - 1][j];
            if (num[i] == j) {
                dp[i][j] = 1;
            } else if (dp[i - 1][j + num[i]]) {
                dp[i][j] = 1;
            } else if (dp[i - 1][abs(j - num[i])]) {
                dp[i][j] = 1;
            }

            if (dp[n][j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
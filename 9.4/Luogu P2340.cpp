#include <bits/stdc++.h>
using namespace std;

int n;
int iq[405], eq[405];
int dp[800010];

int main() {

    // freopen("Luogu P3853.in", "r", stdin);
    // freopen("Luogu P3853.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> iq[i] >> eq[i];
    }

    memset(dp, -0x3f, sizeof(dp));
    dp[400000] = 0;

    for (int i = 1; i <= n; i++) {
        if (iq[i] >= 0) {
            for (int j = 800000; j >= iq[i]; j--) {
                dp[j] = max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        } else {
            for (int j = 0; j <= 800000 + iq[i]; j++) {
                dp[j] = max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        }
    }

    int ans = 0;

    for (int i = 400000; i <= 800000; i++) {
        if (dp[i] >= 0) {
            ans = max(ans, dp[i] + i - 400000);
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
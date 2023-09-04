#include <bits/stdc++.h>
using namespace std;

int n;
int l[20005], r[20005], len[20005];
int dp[20005][2];

int main() {

    // freopen("Luogu P3842.in", "r", stdin);
    // freopen("Luogu P3842.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        len[i] = r[i] - l[i] + 1;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = (r[1] - 1) + (r[1] - l[1]);
    dp[1][1] = r[1] - 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] =
            min(dp[i - 1][0] + abs(r[i] - l[i]) + abs(r[i] - l[i - 1]) + 1,
                dp[i - 1][1] + abs(r[i] - l[i]) + abs(r[i] - r[i - 1]) + 1);
        dp[i][1] =
            min(dp[i - 1][0] + abs(r[i] - l[i]) + abs(l[i] - l[i - 1]) + 1,
                dp[i - 1][1] + abs(r[i] - l[i]) + abs(l[i] - r[i - 1]) + 1);
    }

    cout << min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]) << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
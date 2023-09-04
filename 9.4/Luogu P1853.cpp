#include <bits/stdc++.h>
using namespace std;

int s, n, d;

int w[110], v[110];
int dp[50005];

int main() {

    // freopen("Luogu P1853.in", "r", stdin);
    // freopen("Luogu P1853.out", "w", stdout);

    cin >> s >> n >> d;

    for (int i = 1; i <= d; i++) {
        cin >> w[i] >> v[i];
    }


    for (int year = 1; year <= n; year++) {
        memset(dp, 0, sizeof(dp));

        int t = s / 1000;

        for (int i = 1; i <= d; i++) {
            for (int j = w[i] / 1000; j <= t; j++) {
                dp[j] = max(dp[j], dp[j - w[i] / 1000] + v[i]);
            }
        }
        s += dp[t];
    }

    cout << s << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
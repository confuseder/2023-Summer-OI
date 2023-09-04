#include <bits/stdc++.h>
using namespace std;

int n, T;
int w[10005], t[10005], v[10005];
int dp[10005];

int main() {

    // freopen("Luogu P1833.in", "r", stdin);
    // freopen("Luogu P1833.out", "w", stdout);

    int sth, edh, stm, edm;
    scanf("%d:%d %d:%d %d", &sth, &stm, &edh, &edm, &n);

    if (edm < stm) {
        edm += 60;
        edh--;
    }

    T += (edm - stm) + (edh - sth) * 60;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &w[i], &v[i], &t[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (!t[i]) {
            for (int j = w[i]; j <= T; j++) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
            continue;
        }

        for (int times = 0; times < t[i]; times++) {
            for (int j = T; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[T];

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
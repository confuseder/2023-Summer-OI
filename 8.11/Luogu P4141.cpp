#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> w;
long long dp[2005];
long long f[2005];

int main() {

    cin >> n >> m;
    w.push_back(-1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        w.push_back(x);
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] += dp[j - w[i]] % 10;
        }
    }

    for (int i = 1; i <= n; i++) {
        memcpy(f, dp, sizeof(dp));
        for (int j = w[i]; j <= m; j++) {
            f[j] -= f[j - w[i]] % 10;
        }
        for (int j = 1; j <= m; j++) {
            cout << f[j] % 10;
        }
        cout << endl;
    }

    return 0;
}

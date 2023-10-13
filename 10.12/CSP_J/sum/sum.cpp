#include <bits/stdc++.h>
using namespace std;

int n;
long long a[(long long)(1e6 + 10)];
std::vector<long long> e[(long long)(1e6 + 10)];
long long ans = -1e18;
long long dp[(long long)(1e6 + 10)];
long long sum[(long long)(1e6 + 10)];

void dfs(int x, int fa) {
    int siz = e[x].size();
    sum[x]  = a[x];
    for (int i = 0; i <= siz - 1; i++) {
        int y = e[x][i];
        if (y == fa)
            continue;
        dfs(y, x);
        sum[x] += sum[y];
        if (dp[x] > -1e18)
            ans = max(ans, dp[x] + dp[y]);
        dp[x] = max(dp[x], dp[y]);
    }
    dp[x] = max(dp[x], sum[x]);
}

int main(int argc, char *argv[]) {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        dp[i] = -1e18;

    dfs(1, -1);
    if (ans == 1e18)
        puts("Impossible");
    else
        printf("%lld\n", ans);
    return 0;
}
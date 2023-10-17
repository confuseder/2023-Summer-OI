#include <bits/stdc++.h>
using namespace std;

int n, mx;
int lf[200005], ri[200005];
long long dp[200005][2];
long long ans;
vector<int> boxs;

int main() {

    // freopen("case.in", "r", stdin);
    // freopen("case.out", "w", stdout);

    memset(lf, 0x3f3f3f, sizeof(lf));
    memset(ri, -0x3f3f3f, sizeof(ri));
    memset(dp, 127, sizeof(dp));
    lf[0] = ri[0] = 0;
    dp[0][0] = dp[0][1] = 0;
    boxs.push_back(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        lf[b] = min(lf[b], a);
        ri[b] = max(ri[b], a);
        mx    = max(mx, b);
        boxs.push_back(b);
    }

    sort(boxs.begin(), boxs.end());
    boxs.erase(unique(boxs.begin(), boxs.end()), boxs.end());

    for (auto i = ++boxs.begin(); i != boxs.end(); i++) {
        // 停在左边
        // 1. 上方左端点到右端点
        int pr    = *prev(i);
        dp[*i][0] = min(dp[*i][0], (dp[pr][0] + llabs(lf[pr] - ri[*i]) +
                                    llabs(ri[*i] - lf[*i])));
        // 2. 上方右端点到右端点
        dp[*i][0] = min(dp[*i][0], (dp[pr][1] + llabs(ri[pr] - ri[*i]) +
                                    llabs(ri[*i] - lf[*i])));
        // 停在右边
        // 1. 上方左端点到左端点
        dp[*i][1] = min(dp[*i][1], (dp[pr][0] + llabs(lf[pr] - lf[*i]) +
                                    llabs(ri[*i] - lf[*i])));
        // 2. 上方右端点到左端点
        dp[*i][1] = min(dp[*i][1], (dp[pr][1] + llabs(ri[pr] - lf[*i]) +
                                    llabs(ri[*i] - lf[*i])));
    }

    ans = min((dp[mx][0] + llabs(lf[mx])), (dp[mx][1] + llabs(ri[mx])));

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
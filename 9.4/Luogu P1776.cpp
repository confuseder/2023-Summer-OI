#include <bits/stdc++.h>
using namespace std;

struct thing {
    int w, v;
};

int n, m;
vector<thing> th;
int dp[40005];

vector<int> solve(int x) {
    vector<int> ans;
    for (int i = 1; i <= x; i <<= 1) {
        ans.push_back(i);
        x -= i;
    }
    if (x) {
        ans.push_back(x);
    }
    return ans;
}

int main() {

    // freopen("Luogu P1776.in", "r", stdin);
    // freopen("Luogu P1776.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int w, v, t;
        cin >> v >> w >> t;
        for (auto j : solve(t)) {
            th.push_back({w * j, v * j});
        }
    }

    for (auto i : th) {
        for (int j = m; j >= i.w; j--) {
            dp[j] = max(dp[j], dp[j - i.w] + i.v);
        }
    }

    cout << dp[m];

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
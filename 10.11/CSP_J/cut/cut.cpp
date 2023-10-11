#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<pair<int, long long>> g;

pair<int, long long> cut(int x) {
    long long tot = 1;
    while (x % 2 == 0) {
        tot *= 2;
        x /= 2;
    }
    return {x, tot};
}

int main() {

    // freopen("cut.in", "r", stdin);
    // freopen("cut.out", "w", stdout);

    cin >> n;

    g.push_back({0, 0});

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto c = cut(x);
        g.push_back({c.first, c.second});
        g[i].second += g[i - 1].second;
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        long long x;
        cin >> x;
        auto fud = lower_bound(g.begin(), g.end(), make_pair(0, x),
                               [](pair<int, long long> a, pair<int, long long> b) {
                                   return a.second < b.second;
                               });
        cout << fud->first << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
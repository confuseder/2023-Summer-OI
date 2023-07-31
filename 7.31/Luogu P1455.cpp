#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> pa;

    dsu(int n) {
        pa.resize(n + 1);
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        if (pa[x] != x) {
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void unite(int x, int y) { pa[find(x)] = find(y); }
};

int n, m, w;
vector<pair<int, int>> clouds;
map<int, pair<int, int>> things;
int dp[10005];

int main() {

    // freopen("Luogu P1455.in", "r", stdin);
    // freopen("Luogu P1455.out", "w", stdout);

    cin >> n >> m >> w;

    dsu gx(n);

    clouds.push_back({-1, -1});
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        clouds.push_back({x, y});
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gx.unite(x, y);
    }

    for (int i = 1; i <= n; i++) {
        things[gx.find(i)].first += clouds[i].first;
        things[gx.find(i)].second += clouds[i].second;
    }

    for (auto it : things) {
        for (int j = w; j >= it.second.first; j--) {
            dp[j] = max(dp[j], dp[j - it.second.first] + it.second.second);
        }
    }

    cout << dp[w] << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
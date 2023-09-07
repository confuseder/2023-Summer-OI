#include <bits/stdc++.h>
using namespace std;

int n, x, y, width, height;
int deep[105];
int dist[105];
bool vis[105];
vector<int> mp[105];
queue<pair<int, int>> q;

int main() {

    // freopen("Luogu P3884.in", "r", stdin);
    // freopen("Luogu P3884.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    cin >> x >> y;

    q.push({1, 0});

    while (!q.empty()) {
        int now = q.front().first;
        int dp  = q.front().second;
        q.pop();

        if (vis[now]) {
            continue;
        }
        vis[now] = true;

        dist[now] = dp;
        deep[dp]++;

        for (auto i : mp[now]) {
            q.push({i, dp + 1});
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans + 1 << endl;
    ans = 0;

    for (int i = 0; i <= n + 2; i++) {
        ans = max(ans, deep[i]);
    }

    cout << ans << endl;

    memset(vis, false, sizeof(vis));

    q.push({x, 0});

    while (!q.empty()) {
        int now = q.front().first;
        int dp  = q.front().second;
        q.pop();

        if (vis[now]) {
            continue;
        }
        vis[now] = true;

        if (now == y) {
            cout << dp << endl;
            break;
        }

        for (int i : mp[now]) {
            q.push({i, (dist[now] > dist[i] ? dp + 2 : dp + 1)});
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
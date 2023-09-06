#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, ans = 1e9;
vector<int> mp[10005];
vector<int> rmp[10005];
bool able[10005], vis[10005];
queue<pair<int, int>> q;

bool dfs(int u) {
    if (vis[u]) {
        return able[u];
    }
    vis[u] = true;

    if (u == t) {
        able[u] = true;
        return true;
    }

    if (mp[u].size() == 0) {
        able[u] = false;
        return false;
    }

    bool flag = true;

    for (auto i : mp[u]) {
        if (!dfs(i)) {
            flag = false;
        }
    }

    if (!flag && u != s) {
        able[u] = false;
        return false;
    }

    able[u] = true;
    return true;
}

int main() {

    // freopen("Luogu P2296.in", "r", stdin);
    // freopen("Luogu P2296.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }

    cin >> s >> t;

    memset(able, false, sizeof(able));
    able[s] = able[t] = true;
    dfs(s);
    memset(vis, false, sizeof(vis));
    q.push({s, 0});

    for (int i = 1; i <= n; i++) {
        cout << able[i] << " ";
    }

    cout << endl;

    while (!q.empty()) {
        int now  = q.front().first;
        int step = q.front().second;
        q.pop();

        if (now == t) {
            ans = min(ans, step);
        }

        vis[now] = true;

        for (auto i : mp[now]) {
            if (able[i] && !vis[i]) {
                q.push({i, step + 1});
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
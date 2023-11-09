#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
vector<vector<pair<int, int>>> mp;
int dist[2005];
int cnt[2005];
bool vis[2005];

int main() {

    // freopen("Luogu P3385.in", "r", stdin);
    // freopen("Luogu P3385.out", "w", stdout);

    cin >> T;

    while (T--) {

        cin >> n >> m;

        memset(dist, 0x3f, sizeof(dist));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, false, sizeof(vis));
        mp.clear();

        mp.resize(n + 5);
        queue<int> q;

        q.push(1);
        dist[1] = 0;
        vis[1]  = true;

        for (int i = 1; i <= m; i++) {
            int u, v, val;
            cin >> u >> v >> val;
            mp[u].push_back({v, val});
            if (val >= 0) {
                mp[v].push_back({u, val});
            }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            vis[now] = false;

            for (auto i : mp[now]) {
                if (dist[i.first] > dist[now] + i.second) {
                    dist[i.first] = dist[now] + i.second;
                    cnt[i.first]  = cnt[now] + 1;
                    if (cnt[i.first] >= n) {
                        cout << "YES" << endl;
                        goto ed;
                    }
                    if (!vis[i.first]) {
                        q.push(i.first);
                        vis[i.first] = true;
                    }
                }
            }
        }

        cout << "NO" << endl;
    ed:
        continue;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
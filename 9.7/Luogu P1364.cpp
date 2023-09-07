#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dist;
};

struct cmp {
    bool operator()(const node &a, const node &b) const {
        return a.dist > b.dist;
    }
};

int n;
int dist[105][105];
int vis[105];
int p[105];
vector<int> mp[105];

void dijskstra(int s) {
    priority_queue<node, vector<node>, cmp> q;
    memset(vis, 0, sizeof(vis));
    q.push({s, 0});
    dist[s][s] = 0;

    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.id;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;

        for (auto i : mp[u]) {
            dist[s][i] = min(dist[s][i], dist[s][u] + 1);
            if (!vis[i]) {
                q.push({i, dist[s][i]});
            }
        }
    }
}

int main() {

    // freopen("Luogu P1364.in", "r", stdin);
    // freopen("Luogu P1364.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> p[i] >> u >> v;
        if (u != 0) {
            mp[u].push_back(i);
            mp[i].push_back(u);
        }
        if (v != 0) {
            mp[v].push_back(i);
            mp[i].push_back(v);
        }
    }

    memset(dist, 0x3f, sizeof(dist));

    for (int i = 1; i <= n; i++) {
        dijskstra(i);
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++) {
            res += dist[i][j] * p[j];
        }
        ans = min(ans, res);
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dist;
    node(int id, int dist) : id(id), dist(dist) {}
    node() {}
};

struct cmp {
    bool operator()(node a, node b) { return a.dist > b.dist; }
};

int n, m;
long long ans;
int land[10005];
int dist[105][105];
int vis[105];
vector<pair<int, int>> mp[105];

void dijkstra(int s) {
    priority_queue<node, vector<node>, cmp> q;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i <= n + 2; i++) {
        dist[s][i] = 1e9;
    }
    dist[s][s] = 0;
    q.push(node(s, 0));

    while (!q.empty()) {
        auto now = q.top();
        q.pop();

        if (vis[now.id]) {
            continue;
        }
        vis[now.id] = true;

        for (auto i : mp[now.id]) {
            dist[s][i.first] =
                min(dist[s][i.first], dist[s][now.id] + i.second);
            if (!vis[i.first]) {
                q.push(node(i.first, dist[s][i.first]));
            }
        }
    }
}

int main() {

    // freopen("Luogu P2910.in", "r", stdin);
    // freopen("Luogu P2910.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> land[i];
    }

    for (int i = 1; i <= n; i++) {
        int len;
        for (int j = 1; j <= n; j++) {
            cin >> len;
            mp[i].push_back({j, len});
        }
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    for (int i = 1; i < m; i++) {
        ans += dist[land[i]][land[i + 1]];
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
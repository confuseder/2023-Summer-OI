#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dist;
    node(int id, int dist) : id(id), dist(dist) {}
    node() {}
};

struct cmp {
    bool operator()(const node &a, const node &b) const {
        return a.dist > b.dist;
    }
};

int n, m, s;
int dist[10005];
bool vis[10005];
vector<pair<int, int>> mp[10005];
priority_queue<node, vector<node>, cmp> q;

int main() {

    // freopen("Luogu P3371.in", "r", stdin);
    // freopen("Luogu P3371.out", "w", stdout);

    cin >> n >> m >> s;

    for (int i = 0; i <= n + 2; i++) {
        dist[i] = 2147483647;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
    }

    dist[s] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        auto now = q.top();
        q.pop();

        if (vis[now.id]) {
            continue;
        }

        vis[now.id] = true;

        for (auto i : mp[now.id]) {
            dist[i.first] = min(dist[i.first], dist[now.id] + i.second);
            if (!vis[i.first]) {
                q.push({i.first, dist[i.first]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
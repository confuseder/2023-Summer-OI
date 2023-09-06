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

int c, p, st, a, b, ans;
vector<pair<int, int>> mp[100005];
int dist[100005];
bool vis[100005];

void dijkstra(int s) {
    priority_queue<node, vector<node>, cmp> q;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        int now = q.top().id;
        int dis = q.top().dist;
        q.pop();

        if (vis[now]) {
            continue;
        }
        vis[now] = true;

        for (auto i : mp[now]) {
            dist[i.first] = min(dist[i.first], dis + i.second);
            if (!vis[i.first]) {
                q.push({i.first, dist[i.first]});
            }
        }
    }
}

int main() {

    // freopen("Luogu P3003.in", "r", stdin);
    // freopen("Luogu P3003.out", "w", stdout);

    cin >> c >> p >> st >> a >> b;

    for (int i = 1; i <= c; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        mp[u].push_back({v, val});
        mp[v].push_back({u, val});
    }

    dijkstra(st);
    ans += min(dist[a], dist[b]);
    dijkstra(a);
    ans += dist[b];

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
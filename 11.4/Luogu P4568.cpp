#include <bits/stdc++.h>
using namespace std;

struct line {
    int to;
    int dist;
};

struct point {
    int id, dist;
};

struct cmp {
    bool operator()(point a, point b) { return a.dist > b.dist; }
};

int n, m, k;
int s, t;
int ans = 1e9;
vector<line> mp[200005];
int dist[200005];
bool vis[200005];
priority_queue<point, vector<point>, cmp> q;

void add(int u, int v, int val) {
    mp[u].push_back({v, val});
    mp[v].push_back({u, val});
    for (int i = 1; i <= k; i++) {
        mp[u].push_back({v + n, 0});
        mp[v].push_back({u + n, 0});
        mp[u + n].push_back({v + n, val});
        mp[v + n].push_back({u + n, val});
        u += n;
        v += n;
    }
}

int main() {

    // freopen("Luogu P4568.in", "r", stdin);
    // freopen("Luogu P4568.out", "w", stdout);

    cin >> n >> m >> k;

    cin >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        add(u, v, val);
    }

    memset(dist, 0x3f, sizeof(dist));
    vis[s]  = true;
    dist[s] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        auto now = q.top();
        q.pop();

        vis[now.id] = true;

        for (auto i : mp[now.id]) {
            int th_dist = dist[now.id] + i.dist;
            if (th_dist < dist[i.to]) {
                dist[i.to] = th_dist;
                q.push({i.to, th_dist});
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[i * n + t]);
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
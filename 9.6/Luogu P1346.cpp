#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dist;
    node(int id, int dist) : id(id), dist(dist) {}
    node() {}
};

struct cmp {
    bool operator()(const node &a, const node &b) { return a.dist > b.dist; }
};

int n, a, b;
priority_queue<node, vector<node>, cmp> q;
vector<pair<int, int>> mp[100005];
int dist[100005];
bool vis[100005];

int main() {

    // freopen("Luogu P1346.in", "r", stdin);
    // freopen("Luogu P1346.out", "w", stdout);

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        int k, to;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> to;
            mp[i].emplace_back(to, (j == 1 ? 0 : 1));
        }
    }

    for (int i = 1; i <= n + 2; i++) {
        dist[i] = 1e9;
    }

    dist[a] = 0;
    q.push(node(a, 0));

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
                q.push(node(i.first, dist[i.first]));
            }
        }
    }

    if (dist[b] != 1e9) {
        cout << dist[b] << endl;
    } else {
        cout << -1 << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
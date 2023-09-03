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

int n;
vector<pair<int, int>> mp[100];
priority_queue<node, vector<node>, cmp> q;
int dist[10000];
bool visited[10000];

int main() {

    // freopen("Luogu P1529.in", "r", stdin);
    // freopen("Luogu P1529.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char u, v;
        int len;
        cin >> u >> v >> len;
        mp[u - 'A'].push_back({v - 'A', len});
        mp[v - 'A'].push_back({u - 'A', len});
    }

    q.push(node('Z' - 'A', 0));
    memset(dist, 0x3f, sizeof(dist));
    dist['Z' - 'A'] = 0;
    memset(visited, false, sizeof(visited));

    while (!q.empty()) {
        auto now = q.top();
        q.pop();
        if (visited[now.id]) {
            continue;
        }
        visited[now.id] = true;

        for (auto i : mp[now.id]) {
            dist[i.first] = min(dist[i.first], dist[now.id] + i.second);
            if (!visited[i.first]) {
                q.push(node(i.first, dist[i.first]));
            }
        }
    }

    int ans = 1e9, minPoint;

    for (int i = 0; i < 70; i++) {
        if (mp[i].size() > 0 && dist[i] < ans && i != 'Z' - 'A' &&
            'Z' >= i + 'A') {
            ans      = dist[i];
            minPoint = i;
        }
    }

    cout << char('A' + minPoint) << " " << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
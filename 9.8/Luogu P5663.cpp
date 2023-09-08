#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dist;
};

struct cmp {
    bool operator()(node a, node b) { return a.dist > b.dist; }
};

int n, m, Q;
vector<int> mp[100005];
int dist[100005][3];
priority_queue<node, vector<node>, cmp> q;

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    dist[s][2] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        int now = q.top().id;
        int len = q.top().dist;
        q.pop();

        for (auto i : mp[now]) {
            if (dist[i][2] > len + 1 && (len + 1) % 2 == 0) {
                dist[i][2] = len + 1;
                q.push({i, dist[i][2]});
            }
            if (dist[i][1] > len + 1 && (len + 1) % 2 == 1) {
                dist[i][1] = len + 1;
                q.push({i, dist[i][1]});
            }
        }
    }
}

int main() {

    // freopen("Luogu P5663.in", "r", stdin);
    // freopen("Luogu P5663.out", "w", stdout);

    cin >> n >> m >> Q;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dijkstra(1);

    for (int i = 0; i < Q; i++) {
        int a, id;
        cin >> a >> id;
        if ((dist[a][2] == 0 || dist[a][1] == 0) && a != 1) {
            cout << "No" << endl;
            continue;
        }
        if (id % 2 == 0) {
            cout << ((id - dist[a][2] >= 0) ? "Yes" : "No") << endl;
        }
        if(id % 2 == 1){
            cout << ((id - dist[a][1] >= 0) ? "Yes" : "No") << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
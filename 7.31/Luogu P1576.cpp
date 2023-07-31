#include <bits/stdc++.h>
using namespace std;

struct line {
    int to;
    double vlaue;
};

struct node {
    double dis;
    int num;

    bool operator>(const node &other) const { return dis < other.dis; }
};

int n, m, a, b;
vector<line> mp[2005];
double dis[2005];
bool vis[2005];
priority_queue<node, vector<node>, greater<node>> q;

int main() {

    // freopen("Luogu P1576.in", "r", stdin);
    // freopen("Luogu P1576.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int t1, t2, v;
        cin >> t1 >> t2 >> v;
        mp[t2].push_back({t1, ((double)(100 - v) / 100.0)});
        mp[t1].push_back({t2, ((double)(100 - v) / 100.0)});
    }

    cin >> a >> b;

    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    dis[a] = 1;
    q.push({1, a});

    while (!q.empty()) {
        node now = q.top();
        q.pop();

        if (vis[now.num]) {
            continue;
        }
        vis[now.num] = true;

        for (auto it : mp[now.num]) {
            int to     = it.to;
            double val = it.vlaue;
            if (dis[to] < dis[now.num] * val) {
                dis[to] = dis[now.num] * val;
                q.push({dis[to], to});
            }
        }
    }

    printf("%.8lf\n", 100.0 / dis[b]);

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
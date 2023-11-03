#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    int dist;
};

struct cmp {
    bool operator()(node a, node b) { return a.dist > b.dist; }
};

const int Mod = 100003;
int n, m;
vector<int> mp[1000005];
int dist[1000005], cnt[1000005];
bool vis[1000005];
priority_queue<node, vector<node>, cmp> q;

int main() {

    // freopen("Luogu P1144.in", "r", stdin);
    // freopen("Luogu P1144.out", "w", stdout);

    memset(dist, 0x3f, sizeof(dist));

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    dist[1] = 0;
    q.push({1, 0});
    vis[1] = true;
    cnt[1] = 1;

    while (!q.empty()) {
        auto now = q.top();
        q.pop();

        vis[1] = false;

        for (auto i : mp[now.id]) {
            int th_dist = dist[now.id] + 1;
            if (th_dist < dist[i]) {
                cnt[i]  = cnt[now.id];
                dist[i] = th_dist;
                if (!vis[i]) {
                    q.push({i, th_dist});
                    vis[i] = true;
                }
            } else if (th_dist == dist[i]) {
                cnt[i] += cnt[now.id];
                cnt[i] %= Mod;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
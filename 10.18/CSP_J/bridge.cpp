#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int lg2[100005], deep[100005], father[100005][20];
bool vis[100005];
vector<int> mp[100005];

void init() {
    for (int i = 2; i <= 100003; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
}

void dfs(int u, int fa) {
    if (vis[u]) {
        return;
    }
    vis[u] = true;

    deep[u]      = deep[fa] + 1;
    father[u][0] = fa;
    for (int i = 1; i <= lg2[deep[u]]; i++) {
        father[u][i] = father[father[u][i - 1]][i - 1];
    }

    for (auto i : mp[u]) {
        dfs(i, u);
    }
}

int lca(int u, int v) {
    if (deep[u] > deep[v]) {
        swap(u, v);
    }
    while (deep[u] != deep[v]) {
        v = father[v][lg2[deep[v] - deep[u]]];
    }
    if (u == v) {
        return u;
    }
    for (int i = lg2[deep[u]]; i >= 0; i--) {
        if (father[u][i] != father[v][i]) {
            u = father[u][i];
            v = father[v][i];
        }
    }
    return father[u][0];
}

int main() {

    // freopen("bridge.in", "r", stdin);
    // freopen("bridge.out", "w", stdout);

    init();
    cin >> n >> m;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int fa  = lca(u, v);
        int len = (deep[u] - deep[fa]) + (deep[v] - deep[fa]);
        if (len % 2 == 1) {
            cout << 'Y' << endl;
        } else {
            cout << 'N' << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
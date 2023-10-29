#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int> chil;
    int val;
};

int n;
int ans = -1e9;
node tree[16005];
bool vis[16005];

int dp(int x) {
    vis[x]  = true;
    int num = tree[x].val;

    if (tree[x].chil.empty()) {
        return num;
    }

    for (auto i : tree[x].chil) {
        if (!vis[i]) {
            num += max(0, dp(i));
        }
    }

    tree[x].val = num;

    return num;
}

int main() {

    // freopen("Luogu P1122.in", "r", stdin);
    // freopen("Luogu P1122.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val;
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].chil.push_back(v);
        tree[v].chil.push_back(u);
    }

    dp(1);

    for (int i = 1; i <= n; i++) {
        ans = max(ans, tree[i].val);
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
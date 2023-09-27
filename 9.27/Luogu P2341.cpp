#include <bits/stdc++.h>
using namespace std;

int n, m;
bool in[10005];
int dfn[10005], low[10005], ti, scc;
vector<int> mp[10005];
stack<int> st;
int scc_id[10005];
vector<int> scc_mp[10005];

void tarjan(int u) {
    st.push(u);
    in[u]  = true;
    dfn[u] = low[u] = ++ti;
    for (int v : mp[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        while (true) {
            int t = st.top();
            st.pop();
            in[t]     = false;
            scc_id[t] = scc;
            if (t == u) {
                break;
            }
        }
    }
}

int main() {

    // freopen("Luogu P8436.in", "r", stdin);
    // freopen("Luogu P8436.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            ti = 0;
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : mp[i]) {
            if (scc_id[i] != scc_id[j]) {
                scc_mp[scc_id[i]].push_back(scc_id[j]);
            }
        }
    }

    int ans = -1;

    for (int i = 1; i <= scc; i++) {
        if (scc_mp[i].empty()) {
            if (ans == -1) {
                ans = i;
            } else {
                ans = -1;
                break;
            }
        }
    }

    if (ans == -1) {
        cout << 0 << endl;
    } else {
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            if (scc_id[i] == ans) {
                tot++;
            }
        }
        cout << tot << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
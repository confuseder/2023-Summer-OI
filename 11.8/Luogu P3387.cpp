#include <bits/stdc++.h>
using namespace std;

int n, m, ti;
bool in[10005];
int dfn[10005];
int low[10005];
int dist[10005];
vector<int> mp[10005];
stack<int> st;

int scc;
int cnt[10005];
int scc_id[10005];
int scc_dist[10005];
vector<int> scc_mp[10005];

queue<int> q;
int mx[10005];
int ans;

void tarjan(int u) {
    st.push(u);
    in[u]  = true;
    dfn[u] = low[u] = ++ti;

    for (auto v : mp[u]) {
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
            scc_dist[scc] += dist[t];
            if (t == u) {
                break;
            }
        }
    }
}

int main() {

    // freopen("Luogu P3387.in", "r", stdin);
    // freopen("Luogu P3387.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            //            ti = 0;
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : mp[i]) {
            if (scc_id[i] != scc_id[j]) {
                scc_mp[scc_id[i]].push_back(scc_id[j]);
                cnt[scc_id[j]]++;
            }
        }
    }

    for (int i = 1; i <= scc; i++) {
        if (cnt[i] == 0) {
            q.push(i);
            mx[i] = scc_dist[i];
        }
    }

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (auto i : scc_mp[now]) {
            cnt[i]--;
            mx[i] = max(mx[i], mx[now] + scc_dist[i]);

            if (!cnt[i]) {
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= scc; i++) {
        if (mx[i] > ans) {
            ans = mx[i];
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
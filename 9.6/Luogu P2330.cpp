#include <bits/stdc++.h>
using namespace std;

struct line {
    int u, v, val;
};

struct bx {
    int data[305];

    bx() {
        for (int i = 0; i < 303; i++) {
            data[i] = i;
        }
    }

    int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

    void merge(int x, int y) { data[find(y)] = find(x); }
};

int n, m, ans, cnt;
vector<line> edges;
bx b;

int main() {

    // freopen("Luogu P2330.in", "r", stdin);
    // freopen("Luogu P2330.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        edges.push_back({u, v, val});
    }

    sort(edges.begin(), edges.end(),
         [](line a, line b) { return a.val < b.val; });

    for (int i = 0; (i < m && cnt < n); i++) {
        if (b.find(edges[i].u) != b.find(edges[i].v)) {
            b.merge(edges[i].u, edges[i].v);
            ans = max(ans, edges[i].val);
            cnt++;
        }
    }

    cout << cnt << ' ' << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
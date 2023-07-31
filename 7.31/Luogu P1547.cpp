#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> data;

    dsu(int n) {
        data.resize(n);
        iota(data.begin(), data.end(), 0);
    }

    int find(int x) {
        if (data[x] != x) {
            data[x] = find(data[x]);
        }
        return data[x];
    }

    void merge(int x, int y) { data[find(x)] = find(y); }
};

struct line {
    int u;
    int v;
    int vlaue;
};

int n, m, ans;
vector<line> lines;

int main() {

    // freopen("Luogu P1547.in", "r", stdin);
    // freopen("Luogu P1547.out", "w", stdout);

    cin >> n >> m;
    dsu bx(m + 1);

    for (int i = 0; i < m; i++) {
        int a, b, value;
        cin >> a >> b >> value;

        lines.push_back({a, b, value});
    }

    sort(lines.begin(), lines.end(),
         [](line a, line b) { return a.vlaue < b.vlaue; });

    for (auto it : lines) {
        if (bx.find(it.u) != bx.find(it.v)) {
            bx.merge(it.u, it.v);
            ans = it.vlaue;
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
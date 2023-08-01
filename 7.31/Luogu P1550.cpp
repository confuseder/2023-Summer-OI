#include <bits/stdc++.h>
using namespace std;

struct line {
    int from;
    int to;
    int cost;
};

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

int n, ans;
vector<line> lines;

int main() {

    cin >> n;

    dsu bx(n+2);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        lines.push_back({0, i, x});
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x != 0) {
                lines.push_back({i, j, x});
            }
        }
    }

    sort(lines.begin(), lines.end(),
         [](line a, line b) { return a.cost < b.cost; });

    for (auto it : lines) {
        if (bx.find(it.from) != bx.find(it.to)) {
            ans += it.cost;
            bx.merge(it.from, it.to);
        }
    }

    cout << ans << endl;

    return 0;
}
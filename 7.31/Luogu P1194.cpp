#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> data;

    explicit dsu(int n) {
        data.resize(n);
        iota(data.begin(), data.end(), 0);
    }

    void clear(int n) {
        data.resize(n);
        iota(data.begin(), data.end(), 0);
    }

    int find(int x) {
        if (data[x] != x) {
            data[x] = find(data[x]);
        }
        return data[x];
    }

    void join(int x, int y) { data[find(x)] = find(y); }
};

struct line {
    int from;
    int to;
    int value;
};

int n, money, ans;
dsu bx(0);
set<int> things;
vector<line> lines;

int main() {

    cin >> money >> n;
    bx.clear(n + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x != 0) {
                lines.push_back({i, j, x});
            }
        }
    }

    sort(lines.begin(), lines.end(),
         [](const line &a, const line &b) { return a.value < b.value; });

    for (auto it : lines) {
        if ((bx.find(it.from) != bx.find(it.to)) && it.value <= money) {
            things.insert(it.to);
            things.insert(it.from);
            bx.join(it.from, it.to);
            ans += it.value;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!things.count(i)) {
            ans += money;
        }
    }

    cout << ans << endl;

    return 0;
}
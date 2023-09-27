#include <bits/stdc++.h>
using namespace std;

struct bx {
    int data[200];
    int len;
    bx(int n) {
        for (int i = 0; i <= n; i++) {
            data[i] = i;
        }
        len = n;
    }

    int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

    void merge(int x, int y) { data[find(x)] = find(y); }

    bool check() {
        for (int i = 2; i <= len; i++) {
            if (find(i) != find(i - 1)) {
                return false;
            }
        }
        return true;
    }
};

int n, m;
vector<pair<int, int>> v;

int main() {

    // freopen("Luogu P1556.in", "r", stdin);
    // freopen("Luogu P1556.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({min(x, y), max(x, y)});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        bx b(n);
        for (int j = 0; j < m; j++) {
            if (i != j) {
                b.merge(v[j].first, v[j].second);
            }
        }
        if (!b.check()) {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
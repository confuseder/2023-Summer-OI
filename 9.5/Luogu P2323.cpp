#include <bits/stdc++.h>
using namespace std;

struct bx {
    int father[10005];

    bx() {
        memset(father, 0, sizeof(father));
        for (int i = 0; i <= 10002; i++) {
            father[i] = i;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fy] = fx;
        }
    }
};

struct line {
    int id, level;
    int u, v;
    int c1, c2;
};

int n, m, k, mx;
vector<line> edge, ans;
bx mp;

int main() {

    // freopen("Luogu P2323.in", "r", stdin);
    // freopen("Luogu P2323.out", "w", stdout);

    cin >> n >> k >> m;

    for (int i = 1; i < m; i++) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        edge.push_back({i, -1, u, v, c1, c2});
    }

    sort(edge.begin(), edge.end(), [](line a, line b) { return a.c1 < b.c1; });

    int cnt = 0;
    for (auto i : edge) {
        if (cnt >= k) {
            break;
        }

        if (mp.find(i.u) != mp.find(i.v)) {
            mp.merge(i.u, i.v);
            ans.push_back({i.id, 1, i.u, i.v, i.c1, i.c2});
            mx = max(mx, i.c1);
            cnt++;
        }
    }

    sort(edge.begin(), edge.end(), [](line a, line b) { return a.c2 < b.c2; });

    for (auto i : edge) {
        if (cnt >= n - 1) {
            break;
        }

        if (mp.find(i.u) != mp.find(i.v)) {
            mp.merge(i.u, i.v);
            ans.push_back({i.id, 2, i.u, i.v, i.c1, i.c2});
            mx = max(mx, i.c2);
            cnt++;
        }
    }

    cout << mx << endl;

    sort(ans.begin(), ans.end(), [](line a, line b) { return a.id < b.id; });

    for (auto i : ans) {
        cout << i.id << ' ' << i.level << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
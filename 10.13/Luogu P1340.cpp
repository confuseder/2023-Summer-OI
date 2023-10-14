#include <bits/stdc++.h>
using namespace std;

struct line {
    int u, v;
    int val, week;
};

int n, w, now;
vector<line> lines;
bool use[6005];
int data[205], ans[6005];

void init() {
    memset(use, false, sizeof(use));
    for (int i = 0; i <= 203; i++) {
        data[i] = i;
    }
}

int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

void merge(int x, int y) { data[find(x)] = find(y); }

int kruskal() {
    init();
    int as = 0, tj = 0;
    for (int i = 0; i < lines.size(); i++) {
        int u = lines[i].u, v = lines[i].v, w = lines[i].week;
        if (find(u) != find(v) && w <= now) {
            use[w] = true;
            merge(u, v);
            as += lines[i].val;
            tj++;
        }
        if (tj == n - 1) {
            break;
        }
    }
    return tj == n - 1 ? as : -1;
}

int main() {

    // freopen("Luogu P1340.in", "r", stdin);
    // freopen("Luogu P1340.out", "w", stdout);

    cin >> n >> w;
    for (int i = 1; i <= w; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        lines.push_back({u, v, val, i});
    }

    sort(lines.begin(), lines.end(),
         [](line a, line b) { return a.val < b.val; });

    now = w;

    ans[w] = kruskal();

    for (int i = w - 1; i >= 1; i--) {
        now = i;
        if (use[i + 1]) {
            ans[i] = kruskal();
        } else {
            ans[i] = ans[i + 1];
        }
        if (ans[i] == -1) {
            for (int j = i; j >= 1; j--) {
                ans[j] = -1;
            }
            break;
        }
    }

    for (int i = 1; i <= w; i++) {
        cout << ans[i] << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
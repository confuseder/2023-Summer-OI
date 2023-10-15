#include <bits/stdc++.h>
using namespace std;

struct li {
    int u, v;
    int val;
};

int n, m, k;
long long ans;
vector<li> lines;
int fa[500005];
long long point[500005];
long long line[500005];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
        if (point[x] - k >= line[x] + 1) {
            line[x]++;
            return true;
        } else {
            return false;
        }
    } else {
        if (point[x] + point[y] - k >= line[x] + line[y] + 1) {
            fa[y] = x;
            point[x] += point[y];
            line[x] += line[y];
            line[x]++;
            return true;
        } else {
            return false;
        }
    }
}

int main() {

    // freopen("problem_3415.in", "r", stdin);
    // freopen("problem_3415.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        lines.push_back({u, v, val});
    }

    for (int i = 0; i <= n + 2; i++) {
        fa[i]    = i;
        point[i] = 1;
        line[i]  = 0;
    }

    sort(lines.begin(), lines.end(), [](li a, li b) { return a.val > b.val; });

    for (auto i : lines) {
        if (merge(i.u, i.v)) {
            ans += i.val;
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
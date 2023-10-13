#include <bits/stdc++.h>
using namespace std;

int n, m, q;
bool line[1000005], column[1000005];
set<int> bl[1000005];
long long cnt_bl;

int main() {

    // freopen("color.in", "r", stdin);
    // freopen("color.out", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // cin >> n >> m >> q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                bl[i].insert(j);
                line[i]   = true;
                column[j] = true;
                cnt_bl++;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (cnt_bl == 0) {
            // cout << -1 << endl;
            printf("%d\n", -1);
            continue;
        }
        if (bl[x].count(y)) {
            // cout << 0 << endl;
            printf("%d\n", 0);
            continue;
        }
        if (line[x] || column[y]) {
            // cout << 1 << endl;
            printf("%d\n", 1);
            continue;
        }
        // cout << 2 << endl;
        printf("%d\n", 2);
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
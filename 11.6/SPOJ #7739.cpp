#include <bits/stdc++.h>
using namespace std;

int ans;
int n, m, c;
int st_min[14][1000005];
int st_max[14][1000005];

int main() {

    // freopen("SPOJ #7739.in", "r", stdin);
    // freopen("SPOJ #7739.out", "w", stdout);

    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        cin >> st_min[0][i];
        st_max[0][i] = st_min[0][i];
    }

    for (int i = 1; i <= __lg(m); i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st_min[i][j] =
                min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
            st_max[i][j] =
                max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 1; i + m - 1 <= n; i++) {
        int l  = i;
        int r  = i + m - 1;
        int lg = __lg(r - l + 1);
        int mi = min(st_min[lg][l], st_min[lg][r - (1 << lg) + 1]);
        int mx = max(st_max[lg][l], st_max[lg][r - (1 << lg) + 1]);
        if (mx - mi <= c) {
            cout << i << endl;
            ans++;
        }
    }

    if (ans == 0) {
        cout << "NONE" << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
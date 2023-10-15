#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[500005], b[500005], c[500005];
long long to_true[500005];
long long ans[500005];

int main() {

    // freopen("reserve.in", "r", stdin);
    // freopen("reserve.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    scanf("%d", &q);

    while (q--) {
        memset(ans, 0, sizeof(ans));
        memset(to_true, -1, sizeof(to_true));

        scanf("%d", &m);

        long long last = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            scanf("%d", &x);
            to_true[x] = last + c[x];
            last       = to_true[x];
        }

        long long last_true = 0;
        for (int i = 1; i <= n; i++) {
            if (to_true[i] == -1) {
                ans[i] = min(ans[i - 1] + b[i], a[i] + last_true);
            } else {
                last_true = to_true[i];
                ans[i]    = min(ans[i - 1], a[i] + last_true);
            }
        }

        cout << ans[n] << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
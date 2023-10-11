#include <bits/stdc++.h>
using namespace std;

long long n, q, all;
long long sum;
long long num[200005];
bool is_all[200005];

int main() {

    // freopen("ds.in", "r", stdin);
    // freopen("ds.out", "w", stdout);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        is_all[i] = false;
        sum += num[i];
    }

    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (is_all[x]) {
                num[x]    = y;
                is_all[x] = false;
                sum += y - all;
            } else {
                sum += y - num[x];
                num[x] = y;
            }
        } else {
            int x;
            cin >> x;
            all = x;
            memset(is_all, true, sizeof(is_all));
            sum = all * n;
        }

        cout << sum << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
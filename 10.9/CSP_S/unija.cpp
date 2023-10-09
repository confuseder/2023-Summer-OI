#include <bits/stdc++.h>
using namespace std;

long long n;
long long high[10000005];
long long hi, ans, mx;

int main() {

    // freopen("unija.in", "r", stdin);
    // freopen("unija.out", "w", stdout);

    cin >> n;

    for (long long i = 1; i <= n; i++) {
        long long w, h;
        cin >> w >> h;
        high[h / 2] = max(high[h / 2], w);
        hi          = max(hi, h / 2);
    }

    for (long long i = hi; i >= 1; i--) {
        mx = max(mx, high[i]);
        ans += mx;
    }

    cout << ans * 2 << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, b, x, y;
long long now, ans;

int main() {

    // freopen("recursion.in", "r", stdin);
    // freopen("recursion.out", "w", stdout);

    cin >> n >> b >> x >> y;

    now = b + x;
    ans += now;

    for (int i = 2; i <= n; i++) {
        if (now - y >= b) {
            now -= y;
        } else {
            now += x;
        }
        ans += now;
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {

    // freopen("Luogu P4549.in", "r", stdin);
    // freopen("Luogu P4549.out", "w", stdout);

    cin >> n;

    cin >> ans;
    ans = abs(ans);

    for (int i = 2; i <= n; i++) {
        int num;
        cin >> num;
        ans = __gcd(ans, abs(num));
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
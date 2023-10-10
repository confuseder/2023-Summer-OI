#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long ans, pip = 1;

int main() {

    // freopen("pipe.in", "r", stdin);
    // freopen("pipe.out", "w", stdout);

    cin >> n >> k;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (long long i = k; i >= 2; i -= 2) {
        pip += (i - 1) + (i - 2);
        ans += 2;
        if (pip >= n) {
            if (pip - (i - 2) >= n) {
                cout << ans - 1 << endl;
            }else{
                cout << ans << endl;
            }
            return 0;
        }
    }

    cout << -1 << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long n, cnt;

int main() {

    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);

    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    while (n > 1) {
        long long w = sqrt(n);
        if (w * w == n) {
            n = w;
            cnt++;
        } else {
            cnt += n - w * w;
            n = w * w;
        }
    }

    cout << cnt + 1 << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
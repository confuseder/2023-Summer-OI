#include <bits/stdc++.h>
using namespace std;

int m, s, t;
int pb, sx;

int main() {

    // freopen("Luogu P1095.in", "r", stdin);
    // freopen("Luogu P1095.out", "w", stdout);

    cin >> m >> s >> t;

    for (int i = 1; i <= t; i++) {
        pb += 17;

        if (m >= 10) {
            sx += 60;
            m -= 10;
        } else {
            m += 4;
        }

        if (sx > pb) {
            pb = sx;
        }

        if (pb >= s) {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    cout << pb << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
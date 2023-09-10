#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long m, lim;
long long a, b, c, d;
long long s;

int main() {

    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);

    cin >> m >> lim;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (s) {
        case 1:
            b = max((ll)0, b - a);
            a = min(lim, a + 50);
            c = min(lim, c + 20);
            d = min(lim, d + 20);
            break;
        case 2:
            a = max((ll)0, a - b);
            b = min(lim, (ll)floorl(b * 1.3));
            c = min(lim, c + 20);
            d /= 2;
            break;
        case 3:
            a = min(lim, (ll)ceill(a * 1.145));
            b = min(lim, b + c);
            c = min(lim, c * 2);
            d /= 2;
            break;
        case 4:
            a = min(lim, a + d);
            b = max((ll)0, b - d);
            c /= 2;
            d = min(lim, (ll)ceill(d * 1.8));
        default:
            break;
        }
        // cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }

    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
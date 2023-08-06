#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int maxn, maxm;

int main() {

    cin >> t;

    while (t--) {
        cin >> n >> m;
        maxn = maxm = 0;

        while (n--) {
            int a;
            cin >> a;
            maxn = max(a, maxn);
        }

        while (m--) {
            int b;
            cin >> b;
            maxm = max(b, maxm);
        }

        if (maxn >= maxm) {
            cout << "Godzilla" << endl;
        } else {
            cout << "MechaGodzilla" << endl;
        }
    }

    return 0;
}
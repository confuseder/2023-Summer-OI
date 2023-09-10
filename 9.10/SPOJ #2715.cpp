#include <bits/stdc++.h>
using namespace std;

int t, n;
double k;
vector<double> num;

bool check(double m) {
    double now = num[0] + m;
    for (int i = 1; i < n; i++) {
        if (now + k < num[i] - m) {
            return false;
        }
        now = min(now + k, num[i] + m);
    }
    return true;
}


int main() {

    // freopen("SPOJ #2715.in", "r", stdin);
    // freopen("SPOJ #2715.out", "w", stdout);

    cin >> t;

    while (t--) {
        cin >> k >> n;

        num.clear();

        for (int i = 0; i < n; i++) {
            double x;
            cin >> x;
            num.push_back(x);
        }

        double l = 0, r = 1e9;

        while (r - l > 1e-6) {
            double m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << fixed << setprecision(3) << l << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
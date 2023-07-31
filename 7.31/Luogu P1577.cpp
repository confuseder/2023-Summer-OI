#include <bits/stdc++.h>
using namespace std;

int n, k;
double all;
vector<double> lines;

bool check(double x) {
    int ans = 0;
    for (auto i : lines) {
        ans += floor(i / x);
    }
    return ans >= k;
}

void solve(double l, double r) {
    double mid = l + (r - l) / 2;

    if (r - l < 1e-9) {
        printf("%.5lf\n", l);
        return;
    }

    if (check(mid)) {
        solve(mid, r);
    } else {
        solve(l, mid);
    }
}

int main() {

    // freopen("Luogu P1577.in", "r", stdin);
    // freopen("Luogu P1577.out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        all += x;
        lines.push_back(x);
    }

    solve(0, all);

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
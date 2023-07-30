#include <bits/stdc++.h>
using namespace std;

double fun(double x) { return (double)((exp(x) + exp(-x)) / 2 + x); }

void solve(double l, double r) {
    double leftMid  = l + (r - l) / 3;
    double rightMid = l + (2 * (r - l)) / 3;

    double valueLeft  = fun(leftMid);
    double valueRight = fun(rightMid);

    if (fabs(valueLeft - valueRight) < 10e-8) {
        printf("%.4lf\n", valueLeft);
        return;
    }

    if (valueLeft < valueRight) {
        solve(l, rightMid);
    } else {
        solve(leftMid, r);
    }
}

int a, b;

int main() {

    // freopen("Accoder #792.in", "r", stdin);
    // freopen("Accoder #792.out", "w", stdout);

    cin >> a >> b;

    solve(a, b);

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
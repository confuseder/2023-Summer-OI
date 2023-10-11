#include <bits/stdc++.h>
using namespace std;

int n;
long long num[200005], lt, mi, mx;

int main() {

    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    sort(num + 1, num + n + 1);

    lt = -1e18;
    for (int i = 1; i <= n; i++) {
        if (lt == -1e18 || num[i] - 1 > lt) {
            mi++;
            lt = num[i] + 1;
        }
    }

    lt = -1e18;
    for (int i = 1; i <= n; i++) {
        if (lt == -1e18 || num[i] - 1 > lt) {
            mx++;
            lt = num[i] - 1;
        } else if (num[i] - 1 == lt) {
            mx++;
            lt = num[i];
        } else if (lt == num[i]) {
            mx++;
            lt = num[i] + 1;
        }
    }

    cout << mi << " " << mx << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
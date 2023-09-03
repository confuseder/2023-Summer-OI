#include <bits/stdc++.h>
using namespace std;

int x, n, now, ans;
vector<int> num;

int main() {

    // freopen("Luogu P1658.in", "r", stdin);
    // freopen("Luogu P1658.out", "w", stdout);

    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end(), [&](int a, int b) { return a < b; });

    if (num[0] != 1) {
        cout << -1 << endl;
        return 0;
    }

    while (now < x) {
        int i;
        for (i = num.size() - 1; i >= 0; i--) {
            if (num[i] <= now + 1) {
                break;
            }
        }

        ans++;
        now += num[i];
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
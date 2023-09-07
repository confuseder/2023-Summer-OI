#include <bits/stdc++.h>
using namespace std;

int q, op, x;
vector<int> num;

int main() {

    // freopen("Luogu P5076.in", "r", stdin);
    // freopen("Luogu P5076.out", "w", stdout);

    cin >> q;
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            cout << lower_bound(num.begin(), num.end(), x) - num.begin() + 1
                 << endl;
        } else if (op == 2) {
            cout << num[x - 1] << endl;
        } else if (op == 3) {
            auto it = lower_bound(num.begin(), num.end(), x);
            if (it != num.begin()) {
                cout << *prev(it) << endl;
            } else {
                cout << -0x7fffffff << endl;
            }
        } else if (op == 4) {
            auto it = upper_bound(num.begin(), num.end(), x);
            if (it != num.end()) {
                cout << *it << endl;
            } else {
                cout << 0x7fffffff << endl;
            }
        } else {
            num.push_back(x);
            sort(num.begin(), num.end());
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
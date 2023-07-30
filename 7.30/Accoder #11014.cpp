#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> nums;

int main() {

    // freopen("Accoder #789.in", "r", stdin);
    // freopen("Accoder #789.out", "w", stdout);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    while (q--) {
        int x;
        cin >> x;
        auto start = lower_bound(nums.begin(), nums.end(), x);
        auto end   = upper_bound(nums.begin(), nums.end(), x);

        if (*start != x) {
            cout << "-1 -1" << endl;
            continue;
        }

        if (start == nums.end()) {
            cout << -1;
        } else {
            cout << start - nums.begin();
        }

        if (end == nums.end()) {
            if (start == nums.end()) {
                cout << ' ' << -1 << endl;
            } else {
                cout << ' ' << n - 1 << endl;
            }
        } else {
            cout << ' ' << end - nums.begin() - 1 << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, ans;
set<int> num;

bool check(int a, int b) {
    string s[5];
    s[0] = to_string(a * (b % 10));
    s[1] = to_string(a * (b / 10));
    s[2] = to_string(a * b);
    s[3] = to_string(a);
    s[4] = to_string(b);

    if (s[0].size() != 3 || s[1].size() != 3 || s[2].size() != 4) {
        return false;
    }

    for (int it = 0; it < 5; it++) {
        for (auto i : s[it]) {
            if (num.find(i - '0') == num.end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    // freopen("Luogu P1211.in", "r", stdin);
    // freopen("Luogu P1211.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.insert(x);
    }

    for (int i = 100; i < 1000; i++) {
        for (int j = 10; j < 100; j++) {
            if (check(i, j)) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
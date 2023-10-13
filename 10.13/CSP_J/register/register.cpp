#include <bits/stdc++.h>
using namespace std;

int n;
int last;
int ans;
set<int> regi;

int main() {

    // freopen("register.in", "r", stdin);
    // freopen("register.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == last + 1) {
            last = x;
        } else {
            regi.insert(x);
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
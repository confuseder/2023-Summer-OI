#include <bits/stdc++.h>
using namespace std;

int n;
bool bit[2000010];

int main() {

    // freopen("revflip.in", "r", stdin);
    // freopen("revflip.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> bit[i];
        if ((n - i + 1) % 2) {
            bit[i] = bit[i] ? 0 : 1;
        }
    }

    for (int i = n; i >= 1; i -= 2) {
        cout << bit[i] << " ";
    }

    for (int i = (n % 2 ? 2 : 1); i <= n; i += 2) {
        cout << bit[i] << " ";
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
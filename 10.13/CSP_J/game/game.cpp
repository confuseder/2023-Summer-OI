#include <bits/stdc++.h>
using namespace std;

int n;
int a;
int mi = 1e9, cnt;

int main() {

    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == mi) {
            cnt++;
        }
        if (a < mi) {
            mi  = a;
            cnt = 1;
        }
    }

    cout << n - cnt << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
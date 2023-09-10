#include <bits/stdc++.h>
using namespace std;

int n, ans;
int num[50005];

int main() {

    // freopen("Luogu P3131.in", "r", stdin);
    // freopen("Luogu P3131.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] = (num[i] + num[i - 1]) % 7;
    }

    for (int i = 0; i <= 6; i++) {
        int s = 0, t = 0;
        for (int j = 0; j <= n; j++) {
            if (num[j] == i) {
                s = j;
                break;
            }
        }
        for (int j = n; j >= 0; j--) {
            if (num[j] == i) {
                t = j;
                break;
            }
        }
        ans = max(ans, t - s);
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
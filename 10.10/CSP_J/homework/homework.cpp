#include <bits/stdc++.h>
using namespace std;

int n;
long long num[100005];
long long mi, ans, mx;

int main() {

    // freopen("homework.in", "r", stdin);
    // freopen("homework.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    sort(num + 1, num + n + 1);

    mi = num[1] * num[2] * num[3];

    mx = n;

    for (int i = 1; i <= n; i++) {
        if (num[i] > mi) {
            mx == i;
            break;
        }
    }

    for (int i = 1; i <= mx; i++) {
        for (int j = i + 1; j <= mx; j++) {
            for (int k = j + 1; k <= mx; k++) {
                if (num[i] * num[j] * num[k] == mi) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
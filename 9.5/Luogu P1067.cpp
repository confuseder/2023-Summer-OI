#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

int main() {

    // freopen("Luogu P1067.in", "r", stdin);
    // freopen("Luogu P1067.out", "w", stdout);

    cin >> n;

    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    if (n == 0) {
        cout << num[0] << endl;
        return 0;
    }

    reverse(num.begin(), num.end());

    for (int i = n; i >= 0; i--) {
        if (num[i] == 0) {
            continue;
        }

        if (num[i] == 1 && i != n) {
            printf("+");
        } else if (num[i] == -1) {
            printf("-");
        } else if (num[i] > 0) {
            if (i != n) {
                printf("+");
            }
            if (num[i] != 1) {
                printf("%d", num[i]);
            }
        } else {
            printf("%d", num[i]);
        }

        if (i == 1) {
            printf("x");
        } else if (i != 0) {
            printf("x^%d", i);
        } else if (i == 0 && (num[i] == 1 || num[i] == -1)) {
            printf("1");
        }
    }

    cout << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
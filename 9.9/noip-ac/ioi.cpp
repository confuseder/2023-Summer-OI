#include <bits/stdc++.h>
using namespace std;

int n;
int problem[4];
int cnt[4];

int main() {

    freopen("ioi.in", "r", stdin);
    freopen("ioi.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        cnt[x]++;
        if (cnt[x] > 50) {
            continue;
        }

        problem[x] = max(problem[x], y);
    }

    for (int i = 1; i <= 3; i++) {
        cout << problem[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
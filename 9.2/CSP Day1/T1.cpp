#include <bits/stdc++.h>
using namespace std;

int n, m, h, w, k, ans;
bool pic[2005][2005];
int pird[2005][2005], pirr[2005][2005];

int get(int x1, int y1, int x2, int y2) {
    int down = pird[y2 - 1][x2] - pird[y2 - 1][x1 - 1] - pird[y1 - 1][x2] +
               pird[y1 - 1][x1 - 1];
    int right = pirr[y2][x2 - 1] - pirr[y2][x1 - 1] - pirr[y1 - 1][x2 - 1] +
                pirr[y1 - 1][x1 - 1];
    return down + right;
}

int main() {

    // freopen("T1.in", "r", stdin);
    // freopen("T1.out", "w", stdout);

    cin >> n >> m >> h >> w >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            pic[i][j] = (c == '1');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pic[i][j] != pic[i + 1][j] && i != n) {
                pird[i][j]++;
            }
            if (pic[i][j] != pic[i][j + 1] && j != m) {
                pirr[i][j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            pird[i][j] += pird[i][j - 1];
            pirr[i][j] += pirr[i][j - 1];
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pird[i][j] += pird[i - 1][j];
            pirr[i][j] += pirr[i - 1][j];
        }
    }

    for (int i = 1; i + h - 1 <= n; i++) {
        for (int j = 1; j + w - 1 <= m; j++) {
            if (get(j, i, j + w - 1, i + h - 1) >= k) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
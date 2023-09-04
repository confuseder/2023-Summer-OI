#include <bits/stdc++.h>
using namespace std;

int n, m;
int A, B, C, D;
int mp[355];
int dp[42][42][42][42];

int main() {

    // freopen("Luogu P1541.in", "r", stdin);
    // freopen("Luogu P1541.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        switch (a) {
        case 1:
            A++;
            break;
        case 2:
            B++;
            break;
        case 3:
            C++;
            break;
        case 4:
            D++;
            break;
        default:
            break;
        }
    }

    dp[0][0][0][0] = mp[1];

    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                for (int d = 0; d <= D; d++) {
                    int r = a + 2 * b + 3 * c + 4 * d + 1;
                    if (a > 0) {
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a - 1][b][c][d] + mp[r]);
                    }
                    if (b > 0) {
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b - 1][c][d] + mp[r]);
                    }
                    if (c > 0) {
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b][c - 1][d] + mp[r]);
                    }
                    if (d > 0) {
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b][c][d - 1] + mp[r]);
                    }
                }
            }
        }
    }

    cout << dp[A][B][C][D] << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
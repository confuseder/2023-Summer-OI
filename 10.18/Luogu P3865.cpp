#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int n, m;
int st[25][100005];

int main() {

    // freopen("Luogu P3865.in", "r", stdin);
    // freopen("Luogu P3865.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &st[0][i]);
    }

    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int len = __lg(r - l + 1);
        printf("%d\n", max(st[len][l], st[len][r - (1 << len) + 1]));
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
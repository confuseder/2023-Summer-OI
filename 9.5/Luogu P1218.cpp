#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int x) {
    if (x == 1) {
        return false;
    }

    if (x == 2) {
        return true;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int num, int len) {
    for (int i = 1; i <= 9; i++) {
        if (prime(num * 10 + i)) {
            if (len == n) {
                printf("%d\n", num * 10 + i);
            } else {
                dfs(num * 10 + i, len + 1);
            }
        }
    }
}

int main() {

    // freopen("Luogu P1218.in", "r", stdin);
    // freopen("Luogu P1218.out", "w", stdout);

    scanf("%d", &n);

    dfs(0, 1);

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
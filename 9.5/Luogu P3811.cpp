#include <bits/stdc++.h>
using namespace std;

int n, p;
int inv[3000005];

int main() {

    // freopen("Luogu P3811.in", "r", stdin);
    // freopen("Luogu P3811.out", "w", stdout);

    cin >> n >> p;

    inv[1] = 1;
    printf("1\n");

    for (int i = 2; i <= n; ++i) {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
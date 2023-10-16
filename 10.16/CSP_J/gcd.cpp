#include <bits/stdc++.h>
#include <locale>
using namespace std;

const long long mod = (1e9 + 7);
long long n;
long long nj = 1;
long long nj_2;

int main() {

    // freopen("gcd.in", "r", stdin);
    // freopen("gcd.out", "w", stdout);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        nj *= i;
        nj %= mod;
        if (i == n / 2) {
            nj_2 = nj;
        }
    }

    if (!(n % 2)) {
        cout << (nj + mod - (nj_2 * nj_2) % mod) % mod << endl;
    } else {
        cout << nj << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
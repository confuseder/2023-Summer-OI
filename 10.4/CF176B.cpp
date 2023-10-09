#include <bits/stdc++.h>
using namespace std;

string st, ed;
int k, len, x;
long long dp[100005][2];
const long long mod = 1e9 + 7;

int main() {

    // freopen("CF176B.in", "r", stdin);
    // freopen("CF176B.out", "w", stdout);

    cin >> st >> ed >> k;

    len = st.length();

    if (st == ed) {
        dp[0][0] = 1;
    } else {
        dp[0][1] = 1;
    }

    if (st.length() != ed.length()) {
        cout << 0 << endl;
    }

    st += st;

    for (int i = 0; i < len; i++) {
        if (st.substr(i, len) == ed) {
            x++;
        }
    }

    for (int i = 1; i <= k; i++) {
        dp[i][0] = ((x * dp[i - 1][1]) + ((x - 1) * dp[i - 1][0])) % mod;
        dp[i][1] =
            (((len - x) * dp[i - 1][0]) + ((len - x - 1) * dp[i - 1][1])) % mod;
    }

    cout << dp[k][0] % mod << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
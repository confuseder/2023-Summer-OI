#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
bool isnp[100005];
vector<int> primes;

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!isnp[i])
            primes.push_back(i);
        for (int p : primes) {
            if (p * i > n)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}

int main() {

    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);

    cin >> n;

    a.reserve(n + 2);
    init(n + 2);
    memset(isnp, 0, sizeof(isnp));
    for(auto i : primes){
        isnp[i] = true;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 0);
    dp[0] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i] = a[i];

        for (int j = i - 1; j >= 0; j--) {
            if (isnp[a[i] + a[j]]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    int maxSum = *max_element(dp.begin(), dp.end());
    cout << maxSum << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
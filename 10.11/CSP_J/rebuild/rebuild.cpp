#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
long long ans=1e18;

int main() {

    // freopen("rebuild.in", "r", stdin);
    // freopen("rebuild.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        long long last = 0;
        long long tot  = 0;
        for (int j = i + 1; j <= n; j++) {
            long long use = floor(last / a[j]) + 1;
            last    = use * a[j];
            tot += use;
        }
        last = 0;
        for (int j = i - 1; j >= 1; j--) {
            long long use = floor(last / a[j]) + 1;
            last    = use * a[j];
            tot += use;
        }
        ans = min(ans, tot);
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
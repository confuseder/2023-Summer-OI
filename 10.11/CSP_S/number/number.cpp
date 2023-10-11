#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[205];
long long ans;

long long C(long long n) { return (n * (n - 1) / 2); }

int main() {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[((x % 200) >= 0 ? (x % 200) : 200 + (x % 200))]++;
    }

    for (int i = 0; i < 200; i++) {
        if (cnt[i] >= 2) {
            ans += C(cnt[i]);
        }
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;

int n;
int used, last;
map<int, int> ls;
long long ans = 1;

int main() {

    // freopen("limited.in", "r", stdin);
    // freopen("limited.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ls[x]++;
    }

    for (auto i : ls) {
        if (used + i.second > i.first) {
            cout << 0 << endl;
            return 0;
        }
        for (int j = (i.first - used); j > (i.first - used) - i.second; j--) {
            ans *= j;
            ans %= Mod;
        }
        used += i.second;
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
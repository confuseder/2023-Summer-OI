#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int thin[100005];
int ans;

int main() {

    // freopen("gift.in", "r", stdin);
    // freopen("gift.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &thin[i]);
    }

    long long temp = 0;
    int cnt = 0;

    for (int i = n; i >= 1; i--) {
        temp += thin[i];
        if (temp > k) {
            cnt++;
            i++;
            temp = 0;
        }
        if (cnt == m) {
            printf("%d\n", i - 1);
            return 0;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
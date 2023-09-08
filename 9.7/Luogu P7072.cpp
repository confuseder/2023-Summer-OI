#include <bits/stdc++.h>
using namespace std;

int n, w;
int num[1000];

int main() {

    // freopen("Luogu P7072.in", "r", stdin);
    // freopen("Luogu P7072.out", "w", stdout);

    cin >> n >> w;
    memset(num, 0, sizeof(num));

    for (int i = 1; i <= n; i++) {
        int now;
        cin >> now;
        num[now]++;
        int nw = max(1, i * w / 100);

        int cnt = 0, ans;
        for (int i = 600; i >= 0; i--) {
            cnt += num[i];
            if (cnt >= nw) {
                ans = i;
                break;
            }
        }
        cout << ans << ' ';
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
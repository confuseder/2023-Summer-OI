#include <bits/stdc++.h>
using namespace std;

int a, b, n, ans;
bool mp[20][20];

void dfs(int x, int y) {
    if (x < 1 || x > a || y < 1 || y > b) {
        return;
    }
    if (mp[x][y]) {
        return;
    }
    if (x == a && y == b) {
        ans++;
        return;
    }
    dfs(x + 1, y);
    dfs(x, y + 1);
}

int main() {

    // freopen("Luogu P1958.in", "r", stdin);
    // freopen("Luogu P1958.out", "w", stdout);

    cin >> a >> b;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = true;
    }

    dfs(1, 1);

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
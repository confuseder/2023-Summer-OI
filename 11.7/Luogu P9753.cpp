#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
string str;
int cnt = 1;
int back[2000005];
int fa[2000005];
int dt[2000005][30];
char t[2000005];

int main() {

    // freopen("Luogu P9753.in", "r", stdin);
    // freopen("Luogu P9753.out", "w", stdout);

    cin >> n;
    cin >> str;

    t[1] = '#';
    back[1]++;
    fa[1] = 1;

    int now = 1;

    for (auto i : str) {
        if (i == t[now]) {
            now = fa[now];
        } else {
            if (dt[now][i - '0'] == 0) {
                dt[now][i - '0'] = ++cnt;
                fa[cnt]          = now;
                t[cnt]           = i;
            }
            now = dt[now][i - '0'];
        }
        ans += back[now]++;
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, st;
pair<char, char> tree[1005];

void dfs(int now) {
    cout << char(now);

    if (tree[now].first != '*') {
        dfs(tree[now].first);
    }
    if (tree[now].second != '*') {
        dfs(tree[now].second);
    }
}

int main() {

    // freopen("Luogu P1305.in", "r", stdin);
    // freopen("Luogu P1305.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char f, l, r;
        cin >> f >> l >> r;
        tree[f] = make_pair(l, r);
        if (i == 1) {
            st = f;
        }
    }

    dfs(st);

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
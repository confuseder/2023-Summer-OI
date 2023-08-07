#include <bits/stdc++.h>
using namespace std;

int n, m;
int rmq[100005][25];

int search(int l, int r) {
    int lg = log2(r - l + 1);
    return min(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]);
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> rmq[i][0];
    }

    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
        }
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << search(l, r) << ' ';
    }

    return 0;
}

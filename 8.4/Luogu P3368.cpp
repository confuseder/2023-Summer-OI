#include <bits/stdc++.h>
using namespace std;

int n, m;
int bit_tree[500005];
int xf[500005];

int lowBit(int x) { return x & (-x); }

void addOne(int x, int val) {
    while (x <= n) {
        bit_tree[x] += val;
        x += lowBit(x);
    }
}

void add(int l, int r, int val) {
    addOne(l, val);
    addOne(r + 1, -val);
}

int sumAll(int x) {
    int res = 0;
    while (x > 0) {
        res += bit_tree[x];
        x -= lowBit(x);
    }
    return res;
}

int sum(int l, int r) { return sumAll(r) - sumAll(l - 1); }

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> xf[i];
        addOne(i, xf[i] - xf[i - 1]);
    }

    for (int i = 1; i <= m; i++) {
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            int l, r, v;
            cin >> l >> r >> v;
            add(l, r, v);
            break;
        case 2:
            int x;
            cin >> x;
            cout << sumAll(x) << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
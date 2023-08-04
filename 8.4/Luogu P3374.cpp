#include <bits/stdc++.h>
using namespace std;

int n, m;
int bit_tree[500005];

int lowBit(int x) { return x & (-x); }

void add(int x, int val) {
    while (x <= n) {
        bit_tree[x] += val;
        x += lowBit(x);
    }
}

int sumAll(int x) {
    int res = 0;
    while (x) {
        res += bit_tree[x];
        x -= lowBit(x);
    }
    return res;
}

int sum(int l, int r) { return sumAll(r) - sumAll(l - 1); }

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }

    for (int i = 1; i <= m; i++) {
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            int x, val;
            cin >> x >> val;
            add(x, val);
            break;
        case 2:
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
            break;
        }
    }

    return 0;
}
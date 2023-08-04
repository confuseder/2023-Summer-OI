#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long bit_tree[1000005];
long long xf[1000005];

long long lowBit(long long x) { return x & (-x); }

void addOne(long long x, long long val) {
    while (x <= n) {
        bit_tree[x] += val;
        x += lowBit(x);
    }
}

void add(long long l, long long r, long long val) {
    addOne(l, val);
    addOne(r + 1, -val);
}

long long sumAll(long long x) {
    long long res = 0;
    while (x > 0) {
        res += bit_tree[x];
        x -= lowBit(x);
    }
    return res;
}

long long sum(long long l, long long r) { return sumAll(r) - sumAll(l - 1); }

int main() {

    cin >> n >> m;

    for (long long i = 1; i <= n; i++) {
        cin >> xf[i];
        addOne(i, xf[i] - xf[i - 1]);
    }

    for (long long i = 1; i <= m; i++) {
        long long ch;
        cin >> ch;
        switch (ch) {
        case 1:
            long long l, r, v;
            cin >> l >> r >> v;
            add(l, r, v);
            break;
        case 2:
            long long x;
            cin >> x;
            cout << sumAll(x) << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
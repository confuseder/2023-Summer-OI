#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long bit_tree[1000005];

long long lowBit(long long x) { return x & (-x); }

void add(long long x, long long val) {
    while (x <= n) {
        bit_tree[x] += val;
        x += lowBit(x);
    }
}

long long sumAll(long long x) {
    long long res = 0;
    while (x) {
        res += bit_tree[x];
        x -= lowBit(x);
    }
    return res;
}

long long sum(long long l, long long r) { return sumAll(r) - sumAll(l - 1); }

int main() {

    cin >> n >> m;

    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        add(i, x);
    }

    for (long long i = 1; i <= m; i++) {
        long long ch;
        cin >> ch;
        switch (ch) {
        case 1:
            long long x, val;
            cin >> x >> val;
            add(x, val);
            break;
        case 2:
            long long l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
            break;
        }
    }

    return 0;
}
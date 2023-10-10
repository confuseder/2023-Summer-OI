#include <bits/stdc++.h>
using namespace std;

struct node {
    long long sum;
    long long lazy;
    int l, r;
};

int n, m;
long long nums[1000000];
node tree[1000000];

void push_up(int u) { tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum; }

void push_down(int u) {
    if (tree[u].lazy != 0) {
        tree[u << 1].lazy += tree[u].lazy;
        tree[u << 1 | 1].lazy += tree[u].lazy;
        tree[u << 1].sum += tree[u].lazy * (tree[u << 1].r - tree[u << 1].l + 1);
        tree[u << 1 | 1].sum += tree[u].lazy * (tree[u << 1 | 1].r - tree[u << 1 | 1].l + 1);
        // tree[u].sum += tree[u].lazy * (tree[u].r - tree[u].l + 1);
        tree[u].lazy = 0;
    }
}

void biuld(int u, int l, int r) {
    tree[u].l = l;
    tree[u].r = r;
    if (l == r) {
        tree[u].sum = nums[l];
        return;
    }
    int mid = (l + r) >> 1;
    biuld(u << 1, l, mid);
    biuld(u << 1 | 1, mid + 1, r);
    push_up(u);
}

long long query(int u, int l, int r) {
    long long ans = 0;
    if (tree[u].l >= l && tree[u].r <= r) {
        return tree[u].sum;
    }
    push_down(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (l <= mid)
        ans += query(u << 1, l, r);
    if (r > mid)
        ans += query(u << 1 | 1, l, r);
    return ans;
}

void update(int u, int l, int r, long long val) {
    if (tree[u].l >= l && tree[u].r <= r) {
        tree[u].lazy += val;
        tree[u].sum += val * (tree[u].r - tree[u].l + 1);
        return;
    }
    push_down(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (l <= mid)
        update(u << 1, l, r, val);
    if (r > mid)
        update(u << 1 | 1, l, r, val);
    push_up(u);
    return;
}

int main() {

    // freopen("Luogu P3372.in", "r", stdin);
    // freopen("Luogu P3372.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }

    biuld(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            long long val;
            scanf("%lld", &val);
            update(1, x, y, val);
        }
        else {
            printf("%lld\n", query(1, x, y));
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
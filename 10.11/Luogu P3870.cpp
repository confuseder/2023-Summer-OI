#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r;
    int up, down;
    int lazy;
};

int n, m;
node tree[400005];

void push_up(int u) {
    tree[u].up   = tree[u << 1].up + tree[u << 1 | 1].up;
    tree[u].down = tree[u << 1].down + tree[u << 1 | 1].down;
}

void push_down(int u) {
    if (tree[u].lazy) {
        swap(tree[u << 1].down, tree[u << 1].up);
        swap(tree[u << 1 | 1].down, tree[u << 1 | 1].up);
        tree[u << 1].lazy ^= 1;
        tree[u << 1 | 1].lazy ^= 1;
        tree[u].lazy = 0;
    }
}

void build(int u, int l, int r) {
    tree[u].l = l, tree[u].r = r;
    if (l == r) {
        tree[u].down = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void update(int u, int l, int r) {
    if (tree[u].l >= l && tree[u].r <= r) {
        tree[u].lazy ^= 1;
        swap(tree[u].down, tree[u].up);
        return;
    }
    push_down(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (l <= mid)
        update(u << 1, l, r);
    if (r > mid)
        update(u << 1 | 1, l, r);
    push_up(u);
}

int query(int u, int l, int r) {
    if (tree[u].l >= l && tree[u].r <= r) {
        return tree[u].up;
    }
    push_down(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans += query(u << 1, l, r);
    if (r > mid)
        ans += query(u << 1 | 1, l, r);
    return ans;
}

int main() {

    // freopen("Luogu P3870.in", "r", stdin);
    // freopen("Luogu P3870.out", "w", stdout);

    cin >> n >> m;

    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 0) {
            update(1, x, y);
        } else {
            printf("%d\n", query(1, x, y));
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
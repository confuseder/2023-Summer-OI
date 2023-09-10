#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[100005];
int km[100005];
int jc[100005];
long long ans;

int find(int x) { return a[x] == x ? x : a[x] = find(a[x]); }

void merge(int x, int y) { a[find(x)] = find(y); }

int main() {

    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 0; i <= n + 2; i++) {
        a[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for (int i = 1; i <= n; i++) {
        km[find(i)]++;
    }

    ans = 1;
    for (int i = 1; i <= n; i++) {
        // cout << km[i] << " ";
        if (km[i] == 0) {
            continue;
        }
        int cnt = k;
        for (int j = 1; j <= km[i]; j++) {
            ans *= cnt;
            ans %= 1000000007;
            --cnt;
        }
    }

    cout << ans % 1000000007 << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
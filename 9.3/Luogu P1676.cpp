#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p;
int ans;

bool check(int x) {
    int cnt = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (last == -1 || abs(p[i] - p[last]) >= x) {
            last = i;
            cnt++;
        }
    }
    return cnt >= m;
}

int main() {

    // freopen("Luogu P1676.in", "r", stdin);
    // freopen("Luogu P1676.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p.push_back(a);
    }

    sort(p.begin(), p.end(), [&](int a, int b) { return a < b; });

    int l = 1, r = 1e9, mid;

    while (r >= l) {
        mid = (r - l) / 2 + l;
        if (check(mid)) {
            ans = mid;
            l   = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
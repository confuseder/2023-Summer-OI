#include <bits/stdc++.h>
using namespace std;

int n, l, ans = 0;
int num[200005];
set<int> s;

int mid(set<int> *s) {
    int mid = s->size() - (int)(s->size() / 2);
    int ans;
    for (auto i = --s->end(); mid > 0; i--, mid--) {
        ans = *i;
    }
    return ans;
}

int main() {

    freopen("emotions.in", "r", stdin);
    freopen("emotions.out", "w", stdout);

    int flag = 0;

    cin >> n >> l;
    if (l == n) {
        flag = 1;
    }
    if (l == 1) {
        flag = 2;
    }
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (l == n) {
            s.insert(num[i]);
        }
        if (l == 1) {
            ans = max(ans, num[i]);
        }
    }

    if (flag == 1) {
        cout << mid(&s) << endl;
        return 0;
    }
    if (flag == 2) {
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= n - l + 1; i++) {
        s.clear();
        for (int j = i; j <= i + l - 1; j++) {
            s.insert(num[j]);
        }
        int mi = mid(&s);
        for (int j = i + l; j <= n; j++) {
            s.insert(num[j]);
            mi = max(mi, mid(&s));
        }
        ans = max(ans, mi);
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
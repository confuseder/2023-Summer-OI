#include <bits/stdc++.h>
using namespace std;

int n, m;
int medic;
vector<int> last;
long long ans;

int main() {

    // freopen("yuanshen.in", "r", stdin);
    // freopen("yuanshen.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            last.push_back(x);
        }
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (x % 2) {
            medic++;
        }
    }

    if (medic >= last.size()) {
        cout << 0 << endl;
    } else {
        sort(last.begin(), last.end());
        for (int i = 0; i < last.size() - medic; i++) {
            ans += last[i];
        }
        cout << ans << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
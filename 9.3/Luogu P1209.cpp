#include <bits/stdc++.h>
using namespace std;

int m, s, c, len;
vector<int> d, p;

int main() {

    // freopen("Luogu P1209.in", "r", stdin);
    // freopen("Luogu P1209.out", "w", stdout);

    cin >> m >> s >> c;

    for (int i = 1; i <= c; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    unique(p.begin(), p.end());
    sort(p.begin(), p.end(), [&](int a, int b) { return a < b; });

    for (int i = 1; i < p.size(); i++) {
        d.push_back(abs(p[i] - p[i - 1]) - 1);
    }

    sort(d.begin(), d.end(), [&](int a, int b) { return a > b; });

    len = p[p.size() - 1] - p[0] + 1;

    if (m > d.size()) {
        cout << p.size() << endl;
        return 0;
    }

    for (int i = 0; i < min(min(m - 1, s - 1), (int)d.size() - 1); i++) {
        len -= d[i];
    }

    cout << len << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
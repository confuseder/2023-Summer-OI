#include <bits/stdc++.h>
using namespace std;

int n, q, ans;
string paint;
set<pair<int, int>> s;

int main() {

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> n >> q;
    cin >> paint;

    paint.insert(paint.begin(), '#');

    for (int i = 1; i <= n;) {
        char st = paint[i];
        int j   = i;
        while (j < n && paint[j + 1] == st) {
            j++;
        }
        s.insert({i, j});
        i = j + 1;
    }

    ans = s.size();

    for (int i = 0; i < q; i++) {
        int ad;
        char change;
        cin >> ad >> change;

        auto it = s.lower_bound({ad, -1});
        if (it->first > ad || it == s.end()) {
            it--;
        }

        if (change == paint[ad]) {
            goto out;
        }

        if (it->first == it->second) {
            if (it != s.begin() && it != prev(s.end()) &&
                change == paint[prev(it)->second] &&
                change == paint[next(it)->first]) {
                pair<int, int> ne = {prev(it)->first, next(it)->second};
                s.erase(prev(it));
                s.erase(next(it));
                s.erase(it);
                s.insert(ne);
            } else if (it != s.begin() && change == paint[prev(it)->second]) {
                pair<int, int> ne = {prev(it)->first, it->second};
                s.erase(prev(it));
                s.erase(it);
                s.insert(ne);
            } else if (it != s.end() && change == paint[next(it)->first]) {
                pair<int, int> ne = {it->first, next(it)->second};
                s.erase(next(it));
                s.erase(it);
                s.insert(ne);
            }
        } else {
            if (it->first == ad) {
                if (it != s.begin() && change == paint[prev(it)->second]) {
                    pair<int, int> th = {it->first + 1, it->second};
                    pair<int, int> pr = {prev(it)->first, it->first};
                    s.erase(prev(it));
                    s.erase(it);
                    s.insert(th);
                    s.insert(pr);
                } else {
                    pair<int, int> th = {it->first + 1, it->second};
                    pair<int, int> pr = {it->first, it->first};
                    s.erase(it);
                    s.insert(th);
                    s.insert(pr);
                }
            } else if (it->second == ad) {
                if (it != s.end() && change == paint[next(it)->second]) {
                    pair<int, int> th = {it->first, it->second - 1};
                    pair<int, int> ne = {it->second, next(it)->second};
                    s.erase(next(it));
                    s.erase(it);
                    s.insert(th);
                    s.insert(ne);
                } else {
                    pair<int, int> th = {it->first, it->second - 1};
                    pair<int, int> ne = {it->second, it->second};
                    s.erase(it);
                    s.insert(th);
                    s.insert(ne);
                }
            } else {
                pair<int, int> fr   = {it->first, ad - 1};
                pair<int, int> ne   = {ad, ad};
                pair<int, int> back = {ad + 1, it->second};
                s.erase(it);
                s.insert(fr);
                s.insert(ne);
                s.insert(back);
            }
        }
    out:
        paint[ad] = change;
        cout << s.size() << endl;
    }

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
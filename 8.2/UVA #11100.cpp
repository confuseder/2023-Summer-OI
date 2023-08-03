#include <bits/stdc++.h>
using namespace std;

int n, maxn;
vector<vector<int>> v;
map<int, int> mp;

int main() {
    while (true) {
        cin >> n;
        v.clear();
        mp.clear();
        maxn = 0;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
            maxn = max(maxn, mp[a]);
        }

        v.resize(maxn);

        for (auto it = mp.begin(); it != mp.end(); it++) {
            sort(v.begin(), v.end(),
                 [](auto &a, auto &b) { return a.size() < b.size(); });
            for (auto &i : v) {
                if (mp[it->first] > 0) {
                    i.push_back(it->first);
                    mp[it->first]--;
                }
            }
        }

        sort(v.begin(), v.end());

        cout << maxn << endl;

        for (const auto &i : v) {
            for(auto it = i.begin(); it!= i.end(); it++){
                cout << *it;
                if (it!= i.end() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
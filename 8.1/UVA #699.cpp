#include <bits/stdc++.h>
using namespace std;

struct node {
    int left;
    int right;
    int val;
    int addr;
};

vector<node> tr;
map<int, int> mp;
int n;

int solve(int now) {
    int x;
    cin >> x;
    if (x == -1) {
        return -1;
    }

    node n{};
    int it = (int)tr.size();
    n.val  = x;
    n.addr = now;
    tr.push_back(n);
    tr[it].left  = solve(now - 1);
    tr[it].right = solve(now + 1);
    return it;
}

int main() {

    while (true) {
        tr.clear();
        mp.clear();
        int re = solve(0);
        if (re == -1) {
            break;
        }

        for (auto i : tr) {
            mp[i.addr] += i.val;
        }

        cout << "Case " << ++n << ":" << endl;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            cout << it->second;
            auto tx = it;
            if (++tx != mp.end()) {
                cout << ' ';
            }
        }

        cout << endl;
        cout << endl;
    }

    return 0;
}
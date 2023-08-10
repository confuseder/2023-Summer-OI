#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> ch = {{'A', 0}, {'C', 1}, {'T', 2},
                               {'G', 3}, {'*', 4}, {'?', 5}};
int ans;
int n;
string str;

struct trie {
    vector<vector<int>> nex;
    vector<int> en;
    queue<pair<int, int>> q;
    bitset<1007> vis[(int)(5e5 + 10)];

    trie() {
        nex.clear();
        en.clear();
        nex.push_back(vector<int>(10));
        en.push_back(0);
    }

    void add(string s) {
        int len = s.size();
        int now = 0;
        for (int i = 0; i < len; i++) {
            if (nex[now].empty()) {
                nex[now].resize(10);
            }
            if (nex[now][ch[s[i]]] == 0) {
                nex[now][ch[s[i]]] = nex.size();
                nex.push_back(vector<int>(10));
                en.push_back(0);
            }
            if (i == len - 1) {
                en[nex[now][ch[s[i]]]]++;
            }
            now = nex[now][ch[s[i]]];
        }
    }

    void find(int now, int len) {

        if (vis[now][len]) {
            return;
        }

        vis[now][len] = true;

        if (len == str.size() && en[now] > 0) {
            ans += en[now];
            en[now] = 0;
            return;
        }

        if (len == str.size()) {
            return;
        }

        if (nex[now][str[len]] != 0 && str[len] != 4 && str[len] != 5) {
            find(nex[now][str[len]], len + 1);
        } else if (str[len] == 4) {
            for (int i = 0; i < 4; i++) {
                if (nex[now][i] != 0) {
                    find(nex[now][i], len + 1);
                    find(nex[now][i], len);
                }
            }
            find(now, len + 1);
        } else if (str[len] == 5) {
            for (int i = 0; i < 4; i++) {
                if (nex[now][i] != 0) {
                    find(nex[now][i], len + 1);
                }
            }
        }
    }
};

trie t;

int main() {

    cin >> str >> n;

    for (auto &it : str) {
        it = ch[it];
    }

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        t.add(x);
    }

    t.find(0, 0);

    cout << n - ans << endl;

    return 0;
}
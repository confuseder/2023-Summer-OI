#include <bits/stdc++.h>
using namespace std;

string deal(string s, char c) {
    string res;
    switch (c) {
    case 'A':
        res += s.substr(4, 4);
        res += s.substr(0, 4);
        break;
    case 'B':
        res += s[3];
        res += s.substr(0, 3);
        res += s[7];
        res += s.substr(4, 3);
        break;
    case 'C':
        res = s;
        swap(res[1], res[6]);
        swap(res[2], res[6]);
        swap(res[1], res[5]);
    default:
        break;
    }

    return res;
}

string t, ans;
char to[3] = {'A', 'B', 'C'};
queue<pair<string, string>> q;
map<string, string> vis;

int main() {

    // freopen("Luogu P2730.in", "r", stdin);
    // freopen("Luogu P2730.out", "w", stdout);

    for (int i = 0; i < 8; i++) {
        string c;
        cin >> c;
        t += c;
    }

    reverse(t.begin() + 4, t.end());

    q.push({"12348765", ""});
    vis["12348765"] = "";
    ans             = "";

    while (!q.empty()) {
        string s  = q.front().first;
        string op = q.front().second;
        q.pop();

        if (s == t) {
            if (ans.length() == 0 || op.length() < ans.length() ||
                (op.length() <= ans.length() && op < ans)) {
                ans = op;
            }
            continue;
        }

        for (int i = 0; i < 3; i++) {
            string res  = deal(s, to[i]);
            string next = op;
            next.push_back(to[i]);
            if (vis.count(res) == 0 || next.length() < vis[res].length() ||
                (next.length() <= vis[res].length() && next < vis[res])) {
                vis[res] = next;
                q.push({res, next});
            }
        }
    }

    cout << ans.length() << endl;
    for (int i = 0; i < ans.length(); i++) {
        cout << ((i % 60 == 0 && i != 0) ? "\n" : "") << ans[i];
    }

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
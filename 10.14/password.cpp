#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
map<int, string> dic;
string buffer;
int bf_cnt;

int main() {

    freopen("password.in", "r", stdin);
    freopen("password.out", "w", stdout);

    cin >> n;

    dic.insert({0, " "});

    for (int i = 1; i <= n; i++) {
        ++cnt;
        string x;
        cin >> x;
        dic.insert({cnt, x});
    }

    int x;
    while (cin >> x) {
        if (dic.find(x) != dic.end()) {
            cout << dic[x];
        }
        if (x == 0 && !buffer.empty()) {
            if (bf_cnt > 1) {
                ++cnt;
                dic.insert({cnt, buffer});
            }
            buffer.clear();
            bf_cnt = 0;
        } else {
            buffer += dic[x];
            bf_cnt++;
        }
    }

    cout << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
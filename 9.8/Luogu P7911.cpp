#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool checker(string s) {
    regex ip(
        R"(^(0|[0-9]|[1-9]\d|1\d{2}|2([0-4][0-9]|5[0-5]))(\.(0|[0-9]|[1-9]\d|1\d{2}|2([0-4][0-9]|5[0-5]))){3}:(0|[1-9][0-9]{0,3}|[1-5][0-9]{0,4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$)");
    return regex_match(s, ip);
}
map<string, int> m;

int main() {

    // freopen("Luogu P7911.in", "r", stdin);
    // freopen("Luogu P7911.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string op, ip;
        cin >> op >> ip;
        if (op == "Server") {
            if (!checker(ip)) {
                cout << "ERR" << endl;
            } else if (m.count(ip)) {
                cout << "FAIL" << endl;
            } else {
                m.insert(make_pair(ip, i));
                cout << "OK" << endl;
            }
        } else if (op == "Client") {
            if (!checker(ip)) {
                cout << "ERR" << endl;
            } else {
                if (m.count(ip)) {
                    cout << m[ip] << endl;
                } else {
                    cout << "FAIL" << endl;
                }
            }
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
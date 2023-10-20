#include <bits/stdc++.h>
using namespace std;

int last = -1, cnt;
int addr[30];
string s, t;

int main() {

    freopen("repeat.in", "r", stdin);
    freopen("repeat.out", "w", stdout);

    cin >> s >> t;

    for (int i = 0; i < 26; i++) {
        addr[s[i] - '0'] = i;
    }

    for (auto i : t) {
        if (last == -1 || addr[i - '0'] <= last) {
            cnt++;
        }
        last = addr[i - '0'];
    }

    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
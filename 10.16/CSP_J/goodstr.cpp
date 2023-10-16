#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[300];
int ans = 1;

int main() {

    // freopen("goodstr.in", "r", stdin);
    // freopen("goodstr.out", "w", stdout);

    cin >> str;

    for (int i = 1; i < str.length(); ++i) {
        if (cnt[(int)str[i]] == 0) {
            cnt[(int)str[i]]++;
        } else {
            ans += 2;
            memset(cnt, 0, sizeof(cnt));
        }
    }

    cout << str.length() - ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
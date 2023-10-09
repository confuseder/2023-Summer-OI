#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int num[1005];

int main() {

    // freopen("password.in", "r", stdin);
    // freopen("password.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                num[j]++;
            }
        }
    }

    for (int i = 0; i < str.length(); i++) {
        if (num[i] > (n - num[i])) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    cout << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string str;
long long ans;
string buffre;
map<string, pair<int, string>> mp({{"100", {0, "00"}},
                                   {"101", {1, "01"}},
                                   {"110", {2, "10"}},
                                   {"111", {4, "01"}},
                                   {"000", {0, "00"}},
                                   {"010", {0, "10"}},
                                   {"001", {0, "01"}},
                                   {"011", {2, "01"}}}

);

int main() {

    // freopen("knot.in", "r", stdin);
    // freopen("knot.out", "w", stdout);

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        buffre.push_back(str[i]);
        if (buffre.length() == 3) {
            ans += mp[buffre].first;
            buffre = mp[buffre].second;
        }
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
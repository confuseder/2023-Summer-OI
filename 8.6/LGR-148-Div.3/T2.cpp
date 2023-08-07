#include <bits/stdc++.h>
using namespace std;

int n, ans;
string str;
pair<char, bool> l[3] = {{'W', true}, {'B', true}, {'R', true}};
int main() {

    cin >> n;
    cin >> str;

    for (auto &it : str) {
        for (auto &i : l) {
            bool picked = false;
            if (i.first == it) {
                picked = true;
                if (!i.second) {
                    i.second = true;
                    ans++;
                }
            } else {
                if (i.second) {
                    ans++;
                    i.second = false;
                }
            }
            if (picked)
                break;
        }
    }

    cout << ans << endl;

    return 0;
}
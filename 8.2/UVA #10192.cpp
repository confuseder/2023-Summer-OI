#include <bits/stdc++.h>
using namespace std;

int a;
string str1, str2;
int dp[1010][1010];

int main() {

    while (true) {
        memset(dp, 0, sizeof(dp));
        getline(cin, str1);
        if (str1[0] == '#') {
            break;
        }
        getline(cin, str2);

        for (auto i = 0; i < str1.length(); i++) {
            if (!isalnum(str1[i]) && str1[i] != ' ') {
                str1.erase(i, 1);
            }
        }

        for (auto i = 0; i < str2.length(); i++) {
            if (!isalnum(str2[i]) && str2[i] != ' ') {
                str2.erase(i, 1);
            }
        }

        for (int i = 1; i <= str1.length(); ++i) {
            for (int j = 1; j <= str2.length(); ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n", ++a,
               dp[str1.length()][str2.length()]);
    }

    return 0;
}
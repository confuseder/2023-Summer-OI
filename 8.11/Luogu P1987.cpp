#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int money;
    int fall;
};

int n, k;
vector<Tree> trees;
int dp[1005];

int main() {

    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }

        trees.clear();
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            Tree t{};
            cin >> t.money;
            trees.push_back(t);
        }

        for (auto &t : trees) {
            cin >> t.fall;
        }

        sort(trees.begin(), trees.end(),
             [](Tree a, Tree b) { return a.fall > b.fall; });

        for (int i = 1; i <= n; ++i) {
            for (int j = k; j > 0; --j) {
                dp[j] = max(dp[j], dp[j - 1] +
                                       max(0, trees[i - 1].money -
                                                  trees[i - 1].fall * (j - 1)));
            }
        }

        int maxx = 0;
        for (int i = 1; i <= k; ++i) {
            maxx = max(maxx, dp[i]);
        }
        cout << maxx << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> num;

int main() {

    // freopen("Luogu P1088.in", "r", stdin);
    // freopen("Luogu P1088.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    for (int i = 1; i <= m; i++) {
        next_permutation(num.begin(), num.end());
    }

    for (auto i : num) {
        cout << i << " ";
    }

    cout << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
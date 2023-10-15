#include <bits/stdc++.h>
using namespace std;

int n, au, now;
vector<pair<int, int>> problem;

int main() {

    // freopen("contest.in", "r", stdin);
    // freopen("contest.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        problem.push_back({a, b});
        now += (100 / a) * b;
    }

    cin >> au;

    if (now >= au) {
        cout << "Already Au." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int ano = ceil(double(au - now) / double(100 / problem[i].first));
        if (ano > problem[i].first - problem[i].second) {
            cout << "NaN" << endl;
        } else {
            cout << ano << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
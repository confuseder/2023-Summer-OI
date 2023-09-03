#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> q;
vector<int> num;

int main() {

    // freopen("T4.in", "r", stdin);
    // freopen("T4.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (q.empty() || abs(a - q.front()) <= abs(a - q.back())) {
            q.push_front(a);
        } else {
            q.push_back(a);
        }
    }

    while (!q.empty()) {
        num.push_back(q.front());
        q.pop_front();
    }

    int ans = 0;

    for (int i = 1; i < num.size(); i++) {
        ans = max(ans, abs(num[i] - num[i - 1]));
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
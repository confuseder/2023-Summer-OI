#include <bits/stdc++.h>
using namespace std;

int t, n, len;
priority_queue<int, vector<int>, less<int>> minp;
priority_queue<int, vector<int>, greater<int>> maxp;

int main() {

    // freopen("SPOJ #16254.in", "r", stdin);
    // freopen("SPOJ #16254.out", "w", stdout);

    cin >> t;
    while (t--) {
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                while (!minp.empty()) {
                    minp.pop();
                }
                while (!maxp.empty()) {
                    maxp.pop();
                }
                len = 0;
                goto next;
            } else if (n == -1) {
                if (len % 2 == 0) {
                    printf("%d\n", minp.top());
                    minp.pop();
                } else {
                    printf("%d\n", maxp.top());
                    maxp.pop();
                }
                --len;
            } else {
                if (maxp.empty() || n > maxp.top()) {
                    maxp.push(n);
                } else {
                    minp.push(n);
                }
                len++;
                while (minp.size() > maxp.size()) {
                    maxp.push(minp.top());
                    minp.pop();
                }
                while (maxp.size() > minp.size() + 1) {
                    minp.push(maxp.top());
                    maxp.pop();
                }
            }
        }
    next:
        0;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
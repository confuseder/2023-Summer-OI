#include <bits/stdc++.h>
using namespace std;

int main() {

    //  freopen("region.in", "r", stdin);
    //  freopen("region.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<long long> counts(2 * m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int min_sum = l[i] + l[j];
            int max_sum = r[i] + r[j];
            for (int k = max(0, min_sum); k <= min(2 * m, max_sum); k++) {
                counts[k]++;
            }
        }
    }

    for (int k = 0; k <= 2 * m; k++) {
        cout << counts[k] << endl;
    }

    //  fclose(stdin);
    //  fclose(stdout);
    return 0;
}
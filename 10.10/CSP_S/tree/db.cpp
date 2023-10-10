#include <iostream>
using namespace std;
int n;
long long f[100000];

int main() {
    
    // freopen("db.in", "r", stdin);
    freopen("db.out", "w", stdout);

    f[0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
        cout << f[i] << ',';
        if (f[i] >= (5 * 1e8)) {
            break;
        }
    }
    return 0;
}

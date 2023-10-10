#include <bits/stdc++.h>
using namespace std;

long double n, s, v1, v2, k;
long double tall = -1, tc;

int main() {

    // freopen("coach.in", "r", stdin);
    // freopen("coach.out", "w", stdout);

    cin >> n >> s >> v1 >> v2 >> k;

    n -= k;
    tc = s / v2;

    while (n > 0) {
        long double last_s    = s - v1 * tc;
        long double pick_up_t = last_s / (v1 + v2);
        long double tpeo      = last_s / v1;
        long double tcar      = pick_up_t * 2 + (s - last_s) / v1;
        cout << last_s << " " << pick_up_t << " " << tpeo << " " << tcar
             << endl;
        if (tcar > tpeo) {
            tc = tcar;
            n -= k;
        } else {
            tall = tpeo;
            break;
        }
    }

    if (tall == -1) {
        // cout << tc;
        printf("%.6Lf", tc);
    } else {
        printf("%.6Lf", tall);
        // cout << tall;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
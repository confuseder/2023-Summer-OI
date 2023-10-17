#include <bits/stdc++.h>
using namespace std;

struct point {
    long long addr;
    long long power;
};

long long n;
long long power, now;
vector<point> points;

int main() {

    // freopen("xaxis.in", "r", stdin);
    // freopen("xaxis.out", "w", stdout);

    cin >> n >> power;

    for (int i = 1; i <= n; i++) {
        long long a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    sort(points.begin(), points.end(),
         [](point a, point b) { return a.addr < b.addr; });

    for (auto i : points) {
        if (now + power >= i.addr) {
            power -= (i.addr - now);
            now = i.addr;
            power += i.power;
        } else {
            break;
        }
    }

    cout << now + power << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
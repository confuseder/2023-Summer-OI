#include <bits/stdc++.h>
#define MAX (1e7 + 10)
using namespace std;

int T, last, num;
int flag[(long long)(1e7 + 10)], nxt[(long long)(1e7 + 10)];

bool check(int x) {
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

void init() {
    for (int i = 1; i <= MAX; i++) {
        if (flag[i]) {
            continue;
        }
        if (check(i)) {
            for (int j = i; j <= MAX; j += i)
                flag[j] = 1;
            continue;
        }
        nxt[last] = i;
        last      = i;
    }
}

int main() {

    // freopen("Luogu P7960.in", "r", stdin);
    // freopen("Luogu P7960.out", "w", stdout);

    init();

    cin >> T;

    while (T--) {
        int num;
        cin >> num;
        cout << (flag[num] ? -1 : nxt[num]) << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
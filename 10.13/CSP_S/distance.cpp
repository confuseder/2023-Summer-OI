#include <bits/stdc++.h>
using namespace std;

int la, lb;
bitset<1000005> al;
int ans = 1e9;

int cont(bitset<1000005> a, int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (a[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    // freopen("distance.in", "r", stdin);
    // freopen("distance.out", "w", stdout);

    int ti = clock();

    string a, b;
    cin >> a >> b;
    la = a.length();
    lb = b.length();
    al.set();
    a = "0" + a;
    b = "0" + b;
    a.append(1000005 - a.size(), '0');
    b.append(1000005 - b.size(), '0');

    bitset<1000005> A(a);
    bitset<1000005> B(b);

    for (int i = 1; i <= la - lb + 1; i++) {
        if (clock() - ti >= 893000*6.7) {
            break;
        }
        auto nowA = A;
        auto nowB = B;
        nowB >>= i - 1;
        bitset<1000005> bf = al << (1000005 - i);
        bitset<1000005> ed = al >> (i + lb);
        nowA |= bf;
        nowB |= bf;
        nowA |= ed;
        nowB |= ed;
        nowA ^= nowB;
        ans = min(ans, cont(nowA, 1000005 - (i + lb - 1) - 1, 1000005 - i - 1));
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
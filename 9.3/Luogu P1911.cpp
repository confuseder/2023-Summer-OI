#include <bits/stdc++.h>
using namespace std;

int n, zx, zy, cnt = 1;
int mp[1030][1030];
map<int, int> out;

void slove(int ly, int lx, int y, int x, int len) {
    if (len == 2) {
        for (int i = ly; i < ly + len; i++) {
            for (int j = lx; j < lx + len; j++) {
                if (mp[i][j] == -1) {
                    mp[i][j] = cnt;
                }
            }
        }
        cnt++;
        return;
    }

    int m;
    if (y <= (ly + len / 2 - 1)) {
        if (x <= (lx + len / 2 - 1)) {
            m = 1;
        } else {
            m = 2;
        }
    } else {
        if (x <= (lx + len / 2 - 1)) {
            m = 3;
        } else {
            m = 4;
        }
    }

    for (int i = 1; i <= 4; i++) {
        if (i != m) {
            switch (i) {
            case 1:
                mp[(ly + len / 2 - 1)][(lx + len / 2 - 1)] = cnt;
                break;
            case 2:
                mp[(ly + len / 2 - 1)][(lx + len / 2 - 1) + 1] = cnt;
                break;
            case 3:
                mp[(ly + len / 2 - 1) + 1][(lx + len / 2 - 1)] = cnt;
                break;
            case 4:
                mp[(ly + len / 2 - 1) + 1][(lx + len / 2 - 1) + 1] = cnt;
                break;
            default:
                break;
            }
        }
    }
    cnt++;

    for (int i = 1; i <= 4; i++) {
        if (i == m) {
            switch (i) {
            case 1:
                slove(ly, lx, y, x, len / 2);
                break;
            case 2:
                slove(ly, lx + len / 2, y, x, len / 2);
                break;
            case 3:
                slove(ly + len / 2, lx, y, x, len / 2);
                break;
            case 4:
                slove(ly + len / 2, lx + len / 2, y, x, len / 2);
                break;
            default:
                break;
            }
        } else {
            switch (i) {
            case 1:
                slove(ly, lx, (ly + len / 2 - 1), (lx + len / 2 - 1), len / 2);
                break;
            case 2:
                slove(ly, lx + len / 2, (ly + len / 2 - 1),
                      (lx + len / 2 - 1) + 1, len / 2);
                break;
            case 3:
                slove(ly + len / 2, lx, (ly + len / 2 - 1) + 1,
                      (ly + len / 2 - 1), len / 2);
                break;
            case 4:
                slove(ly + len / 2, lx + len / 2, (ly + len / 2 - 1) + 1,
                      (lx + len / 2 - 1) + 1, len / 2);
                break;
            default:
                break;
            }
        }
    }
}

int main() {

    // freopen("Luogu P1911.in", "r", stdin);
    // freopen("Luogu P1911.out", "w", stdout);

    cin >> n >> zy >> zx;

    memset(mp, -1, sizeof(mp));
    mp[zy][zx] = 0;

    n = pow(2, n);

    slove(1, 1, zy, zx, n);

    cnt = 0;
    out.insert({0, 0});

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!out.count(mp[i][j])) {
                out.insert({mp[i][j], ++cnt});
            }
            cout << out[mp[i][j]] << " ";
        }
        cout << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
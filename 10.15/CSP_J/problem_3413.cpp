#include <bits/stdc++.h>
using namespace std;

int c[5];
int cn[5][5];

int main() {

    // freopen("problem_3413.in", "r", stdin);
    // freopen("problem_3413.out", "w", stdout);

    cin >> c[1] >> c[2] >> c[3] >> c[4];

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> cn[i][j];
        }
    }

    for (int i = 1; i <= 4; i++) {
        int lj = 0;
        for (int j = 1; j <= 4; j++) {
            lj += cn[j][i];
        }
        if (lj < c[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
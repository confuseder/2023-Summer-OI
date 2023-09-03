#include <bits/stdc++.h>
using namespace std;

struct person {
    int id;
    int score;
    int rank;
};

int n, r, q;
person p[200010];

int main() {

    // freopen("Luogu P1309.in", "r", stdin);
    // freopen("Luogu P1309.out", "w", stdout);

    cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; i++) {
        int a;
        cin >> a;
        p[i].id    = i;
        p[i].score = a;
    }
    for (int i = 1; i <= 2 * n; i++) {
        int a;
        cin >> a;
        p[i].rank = a;
    }

    sort(p + 1, p + 1 + 2 * n, [](person a, person b) {
        return a.score == b.score ? a.id < b.id : a.score > b.score;
    });

    for (int rang = 0; rang < r; rang++) {
        for (int i = 2; i <= 2 * n; i += 2) {
            if (p[i].rank > p[i - 1].rank) {
                p[i].score++;
            } else {
                p[i - 1].score++;
            }
        }
        sort(p + 1, p + 1 + 2 * n, [](person a, person b) {
            return a.score == b.score ? a.id < b.id : a.score > b.score;
        });
    }

    cout << p[q].id << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
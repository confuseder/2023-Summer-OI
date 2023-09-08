#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    int x, y, z;
    long double dist(node a) {
        return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2) + pow(z - a.z, 2));
    }
};

int T, n, h, r, cnt;
vector<node> d;
int data[1005];
vector<node> down, up;

int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

void merge(int x, int y) { data[find(y)] = find(x); }

int main() {

    // freopen("Luogu P3958.in", "r", stdin);
    // freopen("Luogu P3958.out", "w", stdout);

    cin >> T;

    while (T--) {
        cin >> n >> h >> r;

        d.clear();
        down.clear();
        up.clear();
        for (int i = 0; i <= n + 2; i++) {
            data[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            node temp;
            cin >> temp.x >> temp.y >> temp.z;
            temp.id = i;
            d.push_back(temp);
            if (temp.z - r <= 0) {
                down.push_back(temp);
            }
            if (temp.z + r >= h) {
                up.push_back(temp);
            }
            for (int j = 0; j < d.size() - 1; j++) {
                if (d[j].dist(temp) <= r * 2) {
                    merge(d[j].id, temp.id);
                }
            }
        }

        for (auto i : down) {
            for (auto j : up) {
                if (find(i.id) == find(j.id)) {
                    cout << "Yes" << endl;
                    goto next;
                }
            }
        }

        cout << "No" << endl;
    next:
        0;
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
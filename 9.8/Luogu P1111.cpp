#include <bits/stdc++.h>
using namespace std;

int n, m, mxt;
int data[1005];
vector<pair<int, int>> t[100005];

int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        data[fx] = fy;
    }
}

int main() {

    // freopen("Luogu P1111.in", "r", stdin);
    // freopen("Luogu P1111.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i <= n + 2; i++) {
        data[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, ti;
        cin >> u >> v >> ti;
        t[ti].emplace_back(u, v);
        mxt = max(mxt, ti);
    }

    for (int i = 1; i <= mxt; i++) {
        for (auto j : t[i]) {
            merge(j.first, j.second);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            find(i);
        }
        for (int i = 2; i <= n; i++) {
            if (data[i] != data[i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
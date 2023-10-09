#include <bits/stdc++.h>
using namespace std;

int u, v;
int data[100005];

void init() {
    for (int i = 0; i < 100005; i++) {
        data[i] = i;
    }
}

int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

void merge(int x, int y) { data[find(x)] = find(y); }

int main() {

    // freopen("temple.in", "r", stdin);
    // freopen("temple.out", "w", stdout);

    while (true) {
        init();
        int js = 0;
        set<int> s;
        bool flag = true;
        while (true) {
            cin >> u >> v;
            if (u == -1 && v == -1)
                return 0;
            if (u == 0 && v == 0)
                break;
            if (find(u) == find(v)) {
                flag = false;
            }
            merge(u, v);
        }
        if (!flag) {
            cout << "Dangerous" << endl;
        } else {
            cout << "Safe" << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
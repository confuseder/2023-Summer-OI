#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int data[2000005];
int tj[2000005];
vector<int> fa;

void init(int x) {
    for (int i = 0; i <= x + 2; i++) {
        data[i] = i;
    }
}

int find(int x) { return data[x] == x ? x : data[x] = find(data[x]); }

void merge(int x, int y) { data[find(x)] = find(y); }

int main() {

    // freopen("classroom.in", "r", stdin);
    // freopen("classroom.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d", &n, &m);
    init(n);

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    for (int i = 1; i <= n; i++) {
        tj[find(i)]++;
        if (tj[find(i)] == 1) {
            fa.push_back(find(i));
        }
    }

    ans = m;

    for (int i = 0; i < fa.size(); i++) {
        ans -= tj[fa[i]] - 1;
    }

    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}

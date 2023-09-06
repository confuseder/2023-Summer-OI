#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y;
    int dist;
};

int n, m;
int mp[1005][1005];
bool vis[1005][1005];
int to_x[4] = {1, -1, 0, 0};
int to_y[4] = {0, 0, 1, -1};

bool check(int len) {
    queue<node> q;
    memset(vis, 0, sizeof(vis));
    q.push({1, 1, 0});

    while (!q.empty()) {
        
        node now = q.front();
        q.pop();

        if (now.y == n) {
            return true;
        }

        if (mp[now.y][now.x] > len || vis[now.y][now.x]) {
            continue;
        }

        vis[now.y][now.x] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + to_x[i];
            int ny = now.y + to_y[i];

            if (nx < 1 || nx > m || ny < 1 || ny > n) {
                continue;
            }
            if (!vis[ny][nx]) {
                q.push({nx, ny, 0});
            }
        }
    }

    return false;
}

int main() {

    // freopen("Luogu P1902.in", "r", stdin);
    // freopen("Luogu P1902.out", "w", stdout);

    cin >> n >> m;

    int l = 0, r = 0, mid;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            r = max(r, mp[i][j]);
        }
    }

    while (l <= r) {
        mid = (l + r) / 2;

        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
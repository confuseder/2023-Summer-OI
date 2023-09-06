#include <bits/stdc++.h>
using namespace std;

struct thi {
    int id;
    int time;
    int depend;
    vector<int> child;
};

int n;
vector<thi> v;
int ti[20005];
queue<int> q;

int main() {

    // freopen("Luogu P1113.in", "r", stdin);
    // freopen("Luogu P1113.out", "w", stdout);

    cin >> n;

    v.reserve(n + 3);

    for (int i = 1; i <= n; i++) {
        int id, time, depend;
        cin >> id >> time;
        v[id] = {id, time, {}};
        while (true) {
            cin >> depend;
            if (depend == 0) {
                break;
            }
            v[depend].child.push_back(id);
            v[id].depend++;
        }
        if (v[id].depend == 0) {
            q.push(id);
            ti[id] = time;
        }
    }

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (auto i : v[now].child) {
            if (ti[i] <= ti[now] + v[i].time) {
                ti[i] = ti[now] + v[i].time;
                q.push(i);
            }
        }
    }

    int ans = 0, t;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ti[i]);
        if (ans < ti[i]) {
            t = i;
        }
    }
    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);

    system("pause");

    return 0;
}
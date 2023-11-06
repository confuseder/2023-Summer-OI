#include <bits/stdc++.h>
using namespace std;

__int128 __lcm(__int128 a, __int128 b) { return a * b / __gcd(a, b); };

struct fraction {
    __int128 chil, mo;

    void simple() {
        __int128 gcd = __gcd(this->chil, this->mo);
        chil /= gcd;
        mo /= gcd;
    }

    fraction operator+(fraction a) {
        fraction res;
        __int128 lcm = __lcm(this->mo, a.mo);
        res.mo       = lcm;
        res.chil = (this->chil * (lcm / this->mo)) + (a.chil * (lcm / a.mo));
        res.simple();
        return res;
    }

    void operator+=(fraction a) {
        if (this->mo == 0 || this->chil == 0) {
            this->chil = a.chil;
            this->mo   = a.mo;
            this->simple();
        } else {
            fraction res = *this + a;
            this->chil   = res.chil;
            this->mo     = res.mo;
        }
    }

    void operator/=(__int128 a) {
        this->mo *= a;
        this->simple();
    }
};

inline void print(__int128 n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    if (n > 9)
        print(n / 10);
    putchar(n % 10 + '0');
}

int n, m;
vector<int> mp[100005];
queue<int> q;
set<int> ans;
fraction val[100005];
int cnt[100005];
bool vis[100005];

int main() {

    // freopen("Luogu P7113.in", "r", stdin);
    // freopen("Luogu P7113.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        for (int j = 1; j <= d; j++) {
            int to;
            cin >> to;
            cnt[to]++;
            mp[i].push_back(to);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            q.push(i);
            val[i].chil = 1;
            val[i].mo   = 1;
        }
    }

    while (true) {
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            vis[now] = true;

            if (mp[now].empty()) {
                ans.insert(now);
                continue;
            }

            val[now] /= mp[now].size();

            for (auto i : mp[now]) {
                val[i] += val[now];
                cnt[i]--;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0 && !vis[i]) {
                q.push(i);
            }
        }
        if (q.empty()) {
            break;
        }
    }

    for (int i : ans) {
        print(val[i].chil);
        printf(" ");
        print(val[i].mo);
        printf("\n");
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
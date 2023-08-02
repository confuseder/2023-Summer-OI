#include <bits/stdc++.h>
using namespace std;

char mp[10][10];
int nx, ny;

const int mx[4]    = {-1, 1, 0, 0};
const int my[4]    = {0, 0, -1, 1};
const char turn[4] = {'^', '>', 'v', '<'};

void push(int x, int y, int f) {
    int tx = x + mx[f];
    int ty = y + my[f];
    if (tx <= 0 || tx > 8 || ty <= 0 || ty > 8) {
        mp[x][y] = '.';
        return;
    }
    if (mp[tx][ty] == '.') {
        mp[tx][ty] = mp[x][y];
        mp[x][y]   = '.';
    } else {
        push(tx, ty, f);
        mp[tx][ty] = mp[x][y];
        mp[x][y]   = '.';
    }
}

void move(int st) {
    int x = nx;
    int y = ny;
    int f;
    switch (mp[x][y]) {
    case '^':
        f = 0;
        break;
    case 'v':
        f = 1;
        break;
    case '<':
        f = 2;
        break;
    case '>':
        f = 3;
        break;
    }

    for (int i = 0; i < st; ++i) {
        x += mx[f];
        y += my[f];
        if (x <= 0 || x > 8 || y <= 0 || y > 8) {
            break;
        }
        if (mp[x][y] != '.') {
            push(x, y, f);
        }
        mp[x][y]   = mp[nx][ny];
        mp[nx][ny] = '.';
        nx         = x;
        ny         = y;
    }
}

int main() {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == '^' || mp[i][j] == 'v' || mp[i][j] == '<' ||
                mp[i][j] == '>') {
                nx = i;
                ny = j;
            }
        }
    }

    while (true) {
        string act;
        cin >> act;
        if (act == "#") {
            break;
        }

        if (act == "turn") {
            string t;
            cin >> t;
            int f = 0;
            for (int i = 0; i < 4; ++i) {
                if (mp[nx][ny] == turn[i]) {
                    f = i;
                }
            }
            switch (t[0]) {
            case 'l':
                --f;
                break;
            case 'r':
                ++f;
                break;
            case 'b':
                f += 2;
                break;
            }
            if (f == -1) {
                f = 3;
            }
            if (f == 4) {
                f = 0;
            }
            if (f == 5) {
                f = 1;
            }
            mp[nx][ny] = turn[f];
        } else {
            int a;
            cin >> a;
            move(a);
        }
    }

    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            cout << mp[i][j];
        }
        cout << endl;
    }

    return 0;
}
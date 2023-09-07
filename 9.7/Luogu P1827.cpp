#include <bits/stdc++.h>
using namespace std;

string front, mid;

void slove(string fr, string mi) {
    if (fr.length() == 1) {
        cout << fr;
        return;
    }
    
    char root = fr[0];
    int len;
    for (int i = 0; i < mi.length(); i++) {
        if (mi[i] == root) {
            len = i;
            break;
        }
    }
    if (mi[0] != root) {
        slove(fr.substr(1, len), mi.substr(0, len));
    }
    if (len + 1 < mi.length()) {
        slove(fr.substr(len + 1), mi.substr(len + 1));
    }

    cout << root;
}

int main() {

    // freopen("Luogu P1827.in", "r", stdin);
    // freopen("Luogu P1827.out", "w", stdout);

    cin >> mid >> front;

    slove(front, mid);

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
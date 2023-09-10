#include <bits/stdc++.h>
using namespace std;

struct node {
    char val;
    int child[30];
    int isEnd;
    node(char c) : val(c), isEnd(0) { memset(child, -1, sizeof(child)); }
    node() : isEnd(0) { memset(child, -1, sizeof(child)); }
};

int n, m;
vector<node> trie;
int times[20005];

void insert(string s) {
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'A';
        if (trie[now].child[idx] == -1) {
            trie[now].child[idx] = trie.size();
            trie.push_back(node());
        }
        now = trie[now].child[idx];
        if (i == s.size() - 1) {
            trie[now].isEnd++;
        }
    }
}

void dfs(int now) {
    if (trie[now].isEnd > 0) {
        times[trie[now].isEnd]++;
        return;
    }
    for (int i = 0; i < 30; i++) {
        if (trie[now].child[i] != -1) {
            dfs(trie[now].child[i]);
        }
    }
    return;
}

int main() {

    // freopen("SPOJ #2881.in", "r", stdin);
    // freopen("SPOJ #2881.out", "w", stdout);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        trie.clear();
        trie.push_back(node('#'));
        memset(times, 0, sizeof(times));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            insert(s);
        }

        dfs(0);

        for (int i = 1; i <= n; i++) {
            cout << times[i] << endl;
        }
    }
    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
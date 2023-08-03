#include <bits/stdc++.h>

#include <utility>
using namespace std;

struct TreeNode {
    string data;
    map<string, int> child;
    TreeNode() = default;
    explicit TreeNode(string d) { this->data = std::move(d); }
};

int n, ans;
string str;
vector<TreeNode> tree;

void insert(int root, string s) {
    string inStr;
    s.erase(s.begin());

    int del = -1;
    for (auto it = 0; it < s.length(); it++) {
        if (s[it] == '/') {
            del = it;
            break;
        } else {
            inStr += s[it];
        }
    }
    if (tree[root].child.count(inStr) == 0) {
        ans++;
        tree[root].child[inStr] = tree.size();
        tree.emplace_back(inStr);
    }

    if (del == -1) {
        return;
    }
    insert(tree[root].child[inStr], s.substr(del));
}

int main() {

    cin >> n;

    tree.emplace_back();

    while (n--) {
        cin >> str;
        insert(0, str);
        cout << ans << endl;
    }

    return 0;
}
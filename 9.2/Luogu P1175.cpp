#include <bits/stdc++.h>
using namespace std;

int getLevel(char c) {
    switch (c) {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 0;
        break;
    default:
        return -1;
        break;
    }
};

bool cmp(char a, char b) { return getLevel(a) > getLevel(b); }

int calc(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return floor(a / b);
        break;
    case '^':
        return pow(a, b);
        break;
    default:
        return -1;
        break;
    }
}

vector<string> parser(string s) {
    stack<char> num;
    stack<char> op;
    vector<string> res;

    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i])) {
            num.push(s[i]);
            continue;
        }

        if (s[i] == '(') {
            op.push(s[i]);
            continue;
        }

        if (s[i] == ')') {
            while (op.top() != '(') {
                num.push(op.top());
                op.pop();
            }
            op.pop();
            continue;
        }

        if (op.empty() || cmp(s[i], op.top()) ||
            (s[i] == '^' && op.top() == '^')) {
            op.push(s[i]);
        } else {
            while (!op.empty() && !cmp(s[i], op.top())) {
                num.push(op.top());
                op.pop();
            }
            op.push(s[i]);
        }
    }

    while (!op.empty()) {
        num.push(op.top());
        op.pop();
    }

    while (!num.empty()) {
        string ls;
        ls.push_back(num.top());
        res.push_back(ls);
        num.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int ti(string a) {
    if (a[0] == '-') {
        return -stoi(a.substr(1));
    }
    return stoi(a);
}

int solve(vector<string> s) {
    while (s.size() > 1) {
        for (auto i : s) {
            if (i != "#") {
                cout << i << " ";
            }
        }
        cout << endl;

        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i][0]) && s[i].length() == 1 && s[i] != "#") {
                int cal  = calc(ti(s[i - 2]), ti(s[i - 1]), s[i][0]);
                s[i]     = to_string(cal);
                s[i - 1] = s[i - 2] = "#";
                break;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == "#") {
                s.erase(s.begin() + i);
                i--;
            }
        }
    }
    return ti(s[0]);
}

string str;

int main() {

    // freopen("Luogu P1175.in", "r", stdin);
    // freopen("Luogu P1175.out", "w", stdout);

    cin >> str;

    cout << solve(parser(str)) << endl;

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
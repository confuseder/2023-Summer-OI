#include <bits/stdc++.h>
using namespace std;

double t, n;
vector<pair<double, double>> lines;
double fuc[1005][1005][2];

int main() {

    // freopen("parallel.in", "r", stdin);
    // freopen("parallel.out", "w", stdout);

    cin >> t;

    while (t--) {
        lines.clear();
        memset(fuc, 0, sizeof(fuc));
        cin >> n;

        if (n == 3) {
            cout << "Yes" << endl;
            continue;
        }

        for (int i = 1; i <= n; i++) {
            pair<double, double> now;
            cin >> now.second;
            now.first = i;
            lines.push_back(now);
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double k = (lines[j].second - lines[i].second) / (lines[j].first - lines[i].first);
                double b = lines[i].second - k * lines[i].first;
                fuc[i][j][0] = k;
                fuc[i][j][1] = b;
                fuc[j][i][0] = k;
                fuc[j][i][1] = b;
            }
        }

        
    }

    // fclose(stdin);
    // fclose(stdout);

    // system("pause");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
long long num[100005];
long long mi = 1e18, len = 0;

int main() {

    freopen("min.in", "r", stdin);
    freopen("min.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &num[i]);
        num[i] += num[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (llabs(num[j] - num[i - 1]) < mi ||
                ((llabs(num[j] - num[i - 1]) == mi) && j - i + 1 > len)) {
                mi  = llabs(num[j] - num[i - 1]);
                len = j - i + 1;
            }
        }
    }

    printf("%lld\n", mi);
    printf("%lld\n", len);

    fclose(stdin);
    fclose(stdout);

    // system("pause");

    return 0;
}
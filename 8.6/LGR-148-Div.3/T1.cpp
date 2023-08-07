#include <bits/stdc++.h>
using namespace std;

int n;
pair<long long, long long> pw[] = {
    {1, 0},         {4, 2},         {16, 4},        {64, 6},
    {256, 8},       {1024, 10},     {4096, 12},     {16384, 14},
    {65536, 16},    {262144, 18},   {1048576, 20},  {4194304, 22},
    {16777216, 24}, {67108864, 26}, {268435456, 28}};

int main() {

    cin >> n;

    for (int i = 14; i >= 0; i--) {
        if (n > pw[i].first) {
            cout << pw[i].second << endl;
            break;
        }
    }

    return 0;
}
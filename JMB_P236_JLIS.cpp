#include <climits>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr1, arr2;
int n, m;
int dp[101][101];

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;
    }
}

int func(int a, int b) {
    int &res = dp[a][b];
    if (res != -1)
        return res;

    res = 2;
    int bigger = max(arr1[a], arr2[b]);
    for (int i = a + 1; i <= n; i++) {
        if (bigger < arr1[i])
            res = max(res, func(i, b) + 1);
    }
    for (int i = b + 1; i <= m; i++) {
        if (bigger < arr2[i])
            res = max(res, func(a, i) + 1);
    }
    return res;
}

int main() {
    int c = 0;
    cin >> c;

    int tmp = 0;
    while (c-- > 0) {
        arr1.clear();
        arr2.clear();
        cin >> n >> m;
        arr1.push_back(INT_MIN);
        arr2.push_back(INT_MIN);
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            arr1.push_back(tmp);
        }
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            arr2.push_back(tmp);
        }
        init();
        cout << func(0, 0) - 2 << endl;
    }
}
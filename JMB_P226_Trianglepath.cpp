#include <cstring>
#include <iostream>
using namespace std;
int arr[101][101];
int dp[101][101];
int n;

int fou2(int a, int b) {
    if (a == n - 1)
        return arr[a][b];
    int &res = dp[a][b];
    if (res != -1)
        return dp[a][b];
    return res = max(fou2(a + 1, b), fou2(a + 1, b + 1)) + arr[a][b];
}

// int fou(int a, int b) {
//     for (int i = a; i >= 0; i--) {
//         for (int j = b; j >= 0; j--) {
//             arr[i][j] = max(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]);
//         }
//     }
//     return arr[0][0];
// }

int main() {
    int c = 0;
    cin >> c;
    while (c-- > 0) {
        n = 0;
        cin >> n;
        for (int $ = 0; $ < n; $++) {
            for (int j = 0; j <= $; j++) {
                cin >> arr[$][j];
            }
        }
        // cout << fou(n - 2, n - 2) << endl;
        // dp init
        for (int i = 0; i < n; i++)
            memset(dp[i], -1, sizeof(int) * n);
        cout << fou2(0, 0) << endl;
    }
}
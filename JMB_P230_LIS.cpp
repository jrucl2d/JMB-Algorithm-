#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;
int lowerbound(int tar, int size) {
    int mid, left = 0, right = size - 1;
    while (right > left) {
        mid = (left + right) / 2;
        if (tar <= dp[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}
int main() {
    int c = 0;
    cin >> c;
    while (c-- > 0) {
        dp.clear();
        cin >> n;
        int tmp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (dp.empty()) {  // 처음에 비었을 때
                dp.push_back(tmp);
                count++;
            } else {
                if (dp.back() < tmp) {
                    dp.push_back(tmp);
                    count++;
                } else {
                    dp[lowerbound(tmp, dp.size())] = tmp;
                }
            }
        }
        cout << count << endl;
    }
}
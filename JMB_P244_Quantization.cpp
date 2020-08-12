#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, s;
vector<int> arr(101);

int main() {
    int c = 0;
    cin >> c;
    while (c--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.begin() + n);
    }
}
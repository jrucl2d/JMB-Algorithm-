#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 987654321;
using namespace std;

int t;
string n;
int cache[10002];

int classify(int a, int b) {
    string m = n.substr(a, b - a + 1);

    if (m == string(m.size(), m[0])) return 1;

    bool progressive = true;
    for (int i = 0; i < m.size() - 1; i++)
        if (m[i + 1] - m[i] != m[1] - m[0]) progressive = false;

    if (progressive && abs(m[1] - m[0]) == 1) return 2;

    bool alternative = true;
    for (int i = 0; i < m.size(); i++)
        if (m[i] != m[i % 2]) alternative = false;

    if (alternative) return 4;
    if (progressive) return 5;

    return 10;
}

int memorize(int begin) {
    if (begin == n.size()) return 0;

    int &ret = cache[begin];
    if (ret != -1) return ret;

    ret = INF;
    for (int L = 3; L <= 5; L++) {
        if (begin + L <= n.size())
            ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
    }

    return ret;
}

int main() {
    cin >> t;
    while (t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        cout << memorize(0) << "\n";
    }
}
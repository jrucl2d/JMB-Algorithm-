#include <iostream>
#include <vector>
using namespace std;

int func(vector<int> v, int start, int end)
{
    if (start == end)
        return v[start];

    int mid = (start + end) / 2;
    int res = max(func(v, start, mid), func(v, mid + 1, end)); // select the bigger one between left part and right part

    // compare with middle rectangle
    int height = min(v[mid], v[mid + 1]);
    res = max(res, height * 2);

    int left = mid, right = mid + 1;
    while (start <= left && right <= end) // in the range of this part, find the biggest rectangle
    {
    }
    return res;
}

int main()
{
    int c = 0;
    cin >> c;
    while (c-- > 0)
    {
        // Inputs
        int n = 0;
        cin >> n;
        vector<int> fences;
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            fences.push_back(tmp);
        }
        cout << func(fences, 0, n - 1) << endl;
    }
}
// 3
// 7
// 7 1 5 9 6 7 3
// 7
// 1 4 4 4 4 1 1
// 4
// 1 8 2 2
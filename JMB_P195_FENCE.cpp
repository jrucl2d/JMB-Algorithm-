#include <iostream>
#include <vector>
using namespace std;

int func(vector<int> &v, int start, int end)
{
    if (start == end)
        return v[start];

    int mid = (start + end) / 2;
    int res = max(func(v, start, mid), func(v, mid + 1, end));

    int left = mid, right = mid + 1;
    int height = min(v[left], v[right]);
    res = max(res, height * 2); // first middle rectangle

    while (start < left || right < end) // in the range of this part, find the biggest rectangle
    {
        if (right < end && (left == start || v[left - 1] < v[right + 1])) // move left
        {
            height = min(height, v[++right]);
        }
        else
        {
            height = min(height, v[--left]);
        }
        res = max(height * (right - left + 1), res);
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
        vector<int> fences(n, 0);
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            fences[i] = tmp;
        }
        cout << func(fences, 0, n - 1) << endl;
    }
}

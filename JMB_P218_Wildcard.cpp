#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dp[101][101];
string w = "";
int n = 0;
vector<string> ans;

bool func(string &s, int wp, int sp)
{
    int &res = dp[wp][sp];
    if (res != -1)
        return res;
    if (sp < s.size() && wp < w.size() && (w[wp] == '?' || w[wp] == s[sp]))
        return res = func(s, wp + 1, sp + 1);
    if (wp == w.size() && sp == s.size())
        return res = 1;

    if (w[wp] == '*')
    {
        if (func(s, wp + 1, sp) || (sp < s.size() && func(s, wp, sp + 1)))
            return res = 1;
    }
    return res = 0;
}

int main()
{
    int c = 0;

    cin >> c;
    while (c-- > 0)
    {
        ans.clear();
        cin >> w;
        cin >> n;
        string tmp = "";
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;

            for (int j = 0; j < 101; j++)
                for (int k = 0; k < 101; k++)
                    dp[j][k] = -1;

            if (func(tmp, 0, 0))
                ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }
}
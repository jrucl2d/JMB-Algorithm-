#include <iostream>
#include <string>
using namespace std;
// 4
// w
// xbwwb
// xbwxwbbwb
// xxwwwbxwxwbbbwwxxxwwbbbwwwbb

void reverse(string s)
{
    // if (s.size() == 1) // b이거나 w이면
    // {
    //     return;
    // }
    int cp[4] = {1, 0, 0, 0};
    int cpi = 0;
    int cpn = 0;
    bool checkStart = false;
    // xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
    for (int i = 1; i < s.size(); i++)
    {
        if (i == cp[cpi] + cpn && i != 1 && checkStart)
        {
            cp[++cpi] = i;
            checkStart = false;
        }
        if (s[i] == 'x' && checkStart && i < cp[cpi] + cpn)
        {
            cpn += 4;
        }
        else if (s[i] == 'x' && !checkStart)
        {
            checkStart = true;
            cpn = 5;
        }
        else if (s[i] != 'x' && !checkStart && i != 1)
        {
            cp[++cpi] = i;
            cpn = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << cp[i] << endl;
    }
}

int main()
{
    int c = 0;
    reverse("xbwxwbbwb");
    // cin >> c;
    // string tmp = "";
    // while (c-- > 0)
    // {
    //     cin >> tmp;
    //     reverse(tmp);
    // }
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverse(string s)
{
    if (s.size() == 1) // b이거나 w이면 stop
        return s;
    // find points
    vector<string> subst(4, "");
    int cp[4] = {1, 0, 0, 0}; // slice의 시작점을 저장하는 배열
    int cpI = 0;
    int cnt = 0; // 해당 slice의 길이 후보
    if (s[1] == 'x')
        cnt = 5;
    else
        cnt = 1;
    subst[cpI] += s[1];
    for (int i = 2; i < s.size(); i++)
    {
        if (i == cp[cpI] + cnt) // 다음 slice의 시작점
        {
            cp[++cpI] = i;
            cnt = 1;
        }
        if (s[i] == 'x') // x를 만나면 slice 길이 후보를 4를 더함
        {
            cnt += 4;
        }
        subst[cpI] += s[i];
    }
    string res = "x";
    res += reverse(subst[2]);
    res += reverse(subst[3]);
    res += reverse(subst[0]);
    res += reverse(subst[1]);

    return res;
}

int main()
{
    int c = 0;
    cin >> c;
    string tmp = "";
    while (c-- > 0)
    {
        cin >> tmp;
        if (tmp.size() == 1) // 예외 사례
        {
            cout << tmp << endl;
            continue;
        }
        cout << reverse(tmp) << endl;
    }
}
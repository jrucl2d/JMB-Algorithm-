#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
vector<int> linked[10] = {
    {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};

bool isDone(vector<int> arr)
{ // 모든 원소가 12이면 true 출력
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 12)
            return false;
    }
    return true;
}
void push(vector<int> &arr, int num)
{ // num번째 스위치 누르기
    for (int i = 0; i < linked[num].size(); i++)
    {
        arr[linked[num][i]] = arr[linked[num][i]] + 3 == 15 ? 3 : arr[linked[num][i]] + 3; // 12에서 한 번 누르면 다시 3이 된다.
    }
}
int func(vector<int> &arr, int num)
{
    // 기저사례, 마지막 스위치에 도달함
    if (num == 10)
    {
        if (isDone(arr))
        {
            return 0;
        }
        else
            return INF; // 불가능하면 무한대의 수를 리턴
    }

    int ans = INF;
    for (int i = 0; i < 4; i++)
    {                                           // 4번 누르면 제자리로 돌아오므로 총 세 번까지 누를 수 있다.
        ans = min(ans, i + func(arr, num + 1)); // 안 누르고 다음 스위치로 넘기는 경우를 고려
        push(arr, num);
    }
    return ans;
}
int main()
{
    int c;
    cin >> c;
    while (c-- > 0)
    {
        vector<int> clock;
        int tmp;
        for (int i = 0; i < 16; i++)
        {
            cin >> tmp;
            clock.push_back(tmp);
        }
        int ans = func(clock, 0);
        if (ans > INF - 100)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}

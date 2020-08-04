#include <iostream>
#include <vector>

using namespace std;
int arr[101][101];
bool dp[101][101];
int n;

void func()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j])
            {
                int a = i + arr[i][j];
                int b = j + arr[i][j];
                if (a < n)
                    dp[a][j] = true;
                if (b < n)
                    dp[i][b] = true;
            }
        }
    }
}

int main()
{
    int c = 0;
    cin >> c;
    while (c-- > 0)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                dp[i][j] = false; // init dp array
            }
        }
        dp[0][0] = true;
        func();
        if (dp[n - 1][n - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
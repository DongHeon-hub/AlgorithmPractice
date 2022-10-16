#include <bits/stdc++.h>
using namespace std;

string board[52];
int n, m;
int ans = INT_MAX;
int col_end = 0;
int row_end = 0;

void func(int x, int y); // board의 (x,y)부터 다시 칠해야 하는 개수의 최솟값 구하기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    func(0, 0);
    cout << ans << '\n';
    return 0;
}

void func(int x, int y)
{
    
    if (n - x < 8)
        return;

    if (m - y < 8)
    {
        func(++col_end, 0);
        return;
    }

    int temp = 0; // 현재 보는 보드에서 새로 칠해야 하는 개수

    // 왼쪽 위에 w 로 고정

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
            {
                if (board[i][j] != 'W')
                    temp++;
            }

            else
            {
                if (board[i][j] != 'B')
                    temp++;
            }
        }

    }

    ans = min(ans, temp);
    temp = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
            {
                if (board[i][j] != 'B')
                    temp++;
            }

            else
            {
                if (board[i][j] != 'W')
                    temp++;
            }
        }
    }

    ans = min(ans, temp);

    func(x, y + 1);
}
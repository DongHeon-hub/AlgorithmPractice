#include <bits/stdc++.h>
using namespace std;

char board[3100][10000];

// 3*2^(n)패턴을 board에 담는 함수. 인자로는 n, 처음 행,열을 넘겨줌
void solve(int n, int x, int y);
void printBoard(int n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2 * n; j++)
            board[i][j] = ' ';
    }

    solve(n, 0, 0);
    printBoard(n);
    return 0;
}

void solve(int n, int x, int y)
{
    int cury = 0;

    // Base condition
    if (n == 3)
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n - i - 1; j++)
                board[x + i][y + (cury++)] = ' ';

            for (int j = 0; j < 2 * i + 1; j++)
            {
                if (i == 1 && cury == 2)
                {
                    cury++;
                    continue;
                }

                board[x + i][y + (cury++)] = '*';
            }

            cury = 0;
        }

        return;
    }

    // 1번, 2번, 3번 삼각형의 시작 좌표 계산해서 줘야됨

    n /= 2;
    // 1번
    solve(n, x, y + n);

    // 2번
    solve(n, x + n, y);

    // 3번
    solve(n, x + n, y + 2 * n);

    return;
}

void printBoard(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            cout << board[i][j];
        }

        cout << '\n';
    }

    return;
}
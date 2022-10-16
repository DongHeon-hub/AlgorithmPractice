#include <bits/stdc++.h>
using namespace std;

int res[3];
int paper[2200][2200];

void solve(int n, int x, int y); // n*n 행렬의 (x,y)~(x+n, y+n)까지 보면서 색종이 개수 체크
bool check(int n, int x, int y);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }


    solve(n, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}

void solve(int n, int x, int y)
{
    if (n == 1)
    {
        res[paper[x][y] + 1]++;
        return;
    }

    if (check(n,x,y))
    {
        res[paper[x][y] + 1]++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            solve(n / 3, x + i * (n/3), y + j * (n/3));
    }
}

bool check(int n, int x, int y)
{
    int temp = paper[x][y];

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (paper[i][j] != temp)
                return false;
        }
    }

    return true;
}
#include <bits/stdc++.h>
using namespace std;

bool vis[502][502];
int board[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int pic = 0;
    int max_area = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && vis[i][j] == 0)
            {
                int temp = 0;
                vis[i][j] = 1;
                q.push({i, j});
                pic++;

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    temp++;

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;

                        if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                            continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                max_area = max(max_area, temp);
            }
        }
    }

    cout << pic << '\n'
         << max_area;

    return 0;
}
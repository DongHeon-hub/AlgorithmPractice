#include <bits/stdc++.h>
using namespace std;

bool mask[25];
string board[5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int ans = 0;

    for (int i = 0; i < 5; i++)
        cin >> board[i];

    fill(mask + 7, mask + 25, true);

    do
    {
        int cnt = 0; // 인접 수
        int das = 0; // 다솜파 수
        bool vis[5][5]={}, check7[5][5]={};

        queue<pair<int, int>> q;

        for (int i = 0; i < 25; i++)
        {
            if (!mask[i])
            {
                int x = i / 5;
                int y = i % 5;
                check7[x][y] = 1;
                if (q.empty())
                {
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            cnt++;

            if (board[cur.first][cur.second] == 'S')
                das++;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    continue;

                if (vis[nx][ny] == 1 || !check7[nx][ny])
                    continue;

                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        if (das >= 4 && cnt >= 7)
            ans++;

    } while
     (next_permutation(mask, mask + 25));

    cout << ans << '\n';
    return 0;
}
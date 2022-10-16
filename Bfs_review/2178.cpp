#include <bits/stdc++.h>
using namespace std;

int dist[102][102];
int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);

    dist[0][0] = 0;
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny>=m)
                continue;
            
            if(board[nx][ny]==0 || dist[nx][ny]>=0)
                continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1]+1 << '\n';

    return 0;
}
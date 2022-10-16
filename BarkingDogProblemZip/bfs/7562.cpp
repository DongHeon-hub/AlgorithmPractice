#include <bits/stdc++.h>

using namespace std;

int chess[301][301];
int dist[301][301];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;

    int t, l;

    cin >> t;



    while (t--)
    {

        int x, y;
        int px, py;
        cin >> l;
        for (int i = 0; i < l; i++)
            fill(dist[i], dist[i] + l, -1);
            
        cin >> x >> y;
        cin >> px >> py;
        

        q.push({x, y});
        dist[x][y] = 0;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;

                if(dist[nx][ny]>=0)
                    continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

        cout << dist[px][py] << '\n';

    }

    return 0;
}
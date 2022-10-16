#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef struct
{
    int z;
    int x;
    int y;
} pos;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int dist[32][32][32];

string board[32][32];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, R, C;
    int ez, ex, ey;

    while (1)
    {
        bool esc = false;
        queue<pos> q;

        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
            return 0;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                fill(dist[i][j], dist[i][j] + C, -1);
            }
        }

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    if (board[i][j][k] == 'S')
                    {
                        pos e;
                        dist[i][j][k] = 0;

                        e.z = i;
                        e.x = j;
                        e.y = k;
                        q.push(e);
                    }

                    if (board[i][j][k] == 'E')
                    {
                        ez = i;
                        ex = j;
                        ey = k;
                    }
                }
            }
        }

        while (!q.empty() && !esc)
        {
            pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                int nz = cur.z + dz[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L)
                    continue;

                if (dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '#')
                    continue;

                if (nx == ex && ny == ey && nz == ez)
                {
                    cout << "Escaped in " << dist[cur.z][cur.x][cur.y] + 1 << " minute(s).\n";
                    esc = true;
                    break;
                }

                dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
                pos ee;
                ee.z = nz;
                ee.x = nx;
                ee.y = ny;

                q.push(ee);
            }
        }

        if (!esc)
            cout << "Trapped!\n";
    }

    return 0;
}

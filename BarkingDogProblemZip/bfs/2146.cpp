#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = INT_MAX;
int numOfSom = -2; // 발견하는 섬마다 dist에 -2,-3. ''' 를 dist에 적어놓음
int n;
queue<pair<int, int>> q;

bool check(int nx, int ny)
{
    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        return false;

    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                dist[i][j] = -1;
        }
    }


    // 섬에 대한 마킹
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == -1)
            {

                dist[i][j] = numOfSom;
                q.push({i, j});

                numOfSom--;

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (!check(nx, ny))
                            continue;

                        if (board[nx][ny] == 0 || dist[nx][ny] != -1)
                            continue;

                        dist[nx][ny] = dist[cur.first][cur.second];
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    /*
    cout << '\n';
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
            cout << dist[j][k] << ' ';
        cout << '\n';
    }
    */

    // 섬의 개수만큼 진행

    for (int i = -2; i > numOfSom; i--)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                // 섬에 대해 진행
                if (dist[j][k] == i)
                {
                    q.push({j, k});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (!check(nx, ny))
                    continue;

                //육지 및 이미 방문한 바다 거르기
                if (dist[nx][ny] < 0 || dist[nx][ny] > 0)
                    continue;

                // 섬에 바로 맞닿아 있는 바다
                if (dist[cur.first][cur.second] < 0)
                {
                    dist[nx][ny] = 1;

                    for (int t = 0; t < 4; t++)
                    {
                        int w = nx + dx[t];
                        int h = ny + dy[t];
                        if(!check(w,h))
                            continue;
                        //상하좌우 봤는데 다른 섬이 있으면
                        if (dist[w][h] < 0 && dist[w][h] != i)
                            ans = min(ans, dist[nx][ny]);
                    }

                    q.push({nx, ny});
                }

                else
                {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;

                    for (int t = 0; t < 4; t++)
                    {
                        int w = nx + dx[t];
                        int h = ny + dy[t];
                        if(!check(w,h))
                            continue;
                            
                        if (dist[w][h] < 0 && dist[w][h] != i)
                            ans = min(ans, dist[nx][ny]);
                    }

                    q.push({nx, ny});
                }
            }
        }


       /* 
        cout << '\n';
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                cout << dist[j][k] << ' ';
            cout << '\n';
        }
        */

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++){
                if(dist[j][k]>0)
                    dist[j][k] = 0;
            }   
        }
    }

    cout << ans << '\n';

    return 0;
}

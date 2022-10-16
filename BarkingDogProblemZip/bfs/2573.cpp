#include <bits/stdc++.h>
using namespace std;

int ice[301][301];
bool vis[301][301];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int cnt = 0; // 현재 빙산의 수
int ans = 0; // 걸린 년수


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool check = false;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] > 0 && vis[i][j] == 0)
            {
                if(check == true){
                    cout << 0 << '\n';
                    return 0;
                }

                vis[i][j] = 1;
                q.push({i, j});
                check = true;

                while (!q.empty())
                {
                    
                    pair<int, int> cur = q.front();
                    q.pop();
                    cnt++;

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;

                        if (ice[nx][ny] == 0 || vis[nx][ny] != 0)
                            continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    while (1)
    {
        ans++;

        // 이 for문이 1년
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ice[i][j] == 0 && vis[i][j] == 0)
                {
                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;

                            // 만약 얼음인데 방문 됐으면
                            if (ice[nx][ny] == 0 && vis[nx][ny] != 0)
                                continue;

                            if (ice[nx][ny] > 0)
                            {
                                ice[nx][ny] -= 1;
                                if (ice[nx][ny] == 0){
                                    if(cnt == 1){
                                        cout << ans << '\n';
                                        return 0;
                                    }
                                    cnt--;
                                }
                            }

                            else
                            {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        if (cnt == 0)
        {
            cout << 0 << '\n';
            return 0;
        }

        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, false);

        int temp = 0;
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ice[i][j] && vis[i][j]==0)
                {
                    
                    vis[i][j] = 1;
                    q.push({i, j});

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

                            if (vis[nx][ny] == 1 || ice[nx][ny] == 0)
                                continue;

                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }

                    if (temp != cnt)
                    {
                        cout << ans << '\n';
                        return 0;
                    }
                }
            }
        }
    }
}
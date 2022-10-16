#include <bits/stdc++.h>
using namespace std;

int height[102][102];
bool vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ans = 0;
    
    int m = -1;
    queue<pair<int, int>> q;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
            m = max(m, height[i][j]);
        }
    }

    // 잠기지 않는 영역의 최대 개수를 구하기 위해
    // 1이하의 모든 지역이 잠기는 경우부터 최댓값-1이하의 모든 지역이 담기는 경우를 구함
    for (int h = 0; h < m; h++){
        int res = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(height[i][j] > h && vis[i][j] == 0){
                    res++;
                    vis[i][j] = 1;
                    q.push({i, j});

                    while(!q.empty()){
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx<0 || nx >= n || ny<0 || ny>=n)
                                continue;
                            
                            if(vis[nx][ny] == 1 || height[nx][ny] <= h)
                                continue;

                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        for (int k = 0; k<n; k++)
            fill(vis[k], vis[k] + n, false);
        ans = max(ans, res);
    }

    cout << ans << '\n';
    return 0;
}
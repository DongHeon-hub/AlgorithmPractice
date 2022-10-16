#include<bits/stdc++.h>

using namespace std;

int dist[1002][1002];
int board[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> m >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0)
                dist[i][j] = -1;

            if(board[i][j] == 1){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            // 만약 토마토가 처음에 익어있는곳 or 비어있는 곳 or 안익은곳중 방문된곳
            if(board[nx][ny]!=0 || dist[nx][ny]>0)
                continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int res = 0;

    for (int i = 0; i<n; i++){
        for (int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << -1 << '\n';
                return 0;
            }

            res = max(res, dist[i][j]);
        }
    }

    cout << res << '\n';
    return 0;
}
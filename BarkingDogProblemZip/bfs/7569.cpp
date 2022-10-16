#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int first;
    int second;
    int third;
} pos;

int board[102][102][102];
int n, m, h;
int dist[102][102][102];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<pos> q;

void bfs(){
    while(!q.empty()){
        pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++){
            int nx = cur.second + dx[dir];
            int ny = cur.third + dy[dir];
            int nz = cur.first + dz[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            
            if(board[nz][nx][ny] != 0 || dist[nz][nx][ny] >= 0)
                continue;

            dist[nz][nx][ny] = dist[cur.first][cur.second][cur.third] + 1;
            q.push({nz, nx, ny});
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> board[i][j][k];

                if(board[i][j][k] == 1){
                    q.push({i, j, k});
                }

                if(board[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    bfs();

    int ans = 0;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if(dist[i][j][k]==-1){
                    cout << -1 << '\n';
                    return 0;
                }

                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
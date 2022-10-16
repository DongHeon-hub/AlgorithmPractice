#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int vis[52][52];
int board[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int t;
    queue<pair<int, int>> Q;
    cin >> t;

    while(t--){
        cin >> m >> n >> k;

        while(k--){
            int i, j;
            cin >> j >> i;

            board[i][j] = 1;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(board[i][j] == 1 && vis[i][j] == 0){
                    vis[i][j] = 1;
                    Q.push({i, j});
                    ans++;
                    
                    while(!Q.empty()){
                        pair<int, int> cur = Q.front();
                        Q.pop();

                        for (int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if(nx < 0 || nx >= n || ny < 0 || ny>=m)
                                continue;
                            
                            if(board[nx][ny] == 0 || vis[nx][ny])
                                continue;

                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }

                   
                }
            }
        }


            cout << ans << '\n';
        for (int i = 0; i < 52; i++){
            fill(board[i], board[i] + 52, 0);
            fill(vis[i], vis[i] + 52, 0);
        }
        ans = 0;
    }

    

    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(int x, int y){
    vis[x][y] = true;
    Q.push({x, y});

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    int x, y;
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      board[y][x] = 1;
    }
    int res = 0; //지렁이 개수
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 1 && !vis[i][j]) {
          bfs(i, j);
          res++;
        }
      }
    }
    cout << res << "\n";
    for(int i = 0; i < n; i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, false);
    }
  }
  return 0;
}
*/

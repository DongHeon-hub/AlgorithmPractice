#include<bits/stdc++.h>
using namespace std;

int dist1[1002][1002];
int dist2[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int w, h;
string board[1002];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool ispossible = false;

    int t; // test case num
    cin >> t;

    while(t--){
        cin >> w >> h;

        for (int i = 0; i < h; i++){
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }

        for (int i = 0; i < h; i++)
            cin >> board[i];

        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if(board[i][j] == '*'){
                    dist1[i][j] = 0;
                    q1.push({i, j});
                }

                if(board[i][j] == '@'){
                    dist2[i][j] = 0;
                    q2.push({i, j});
                }
            }
        }

        // 불에 대한 bfs

        while(!q1.empty()){
            pair<int, int> cur = q1.front();
            q1.pop();

            for (int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                
                if(dist1[nx][ny] >= 0 || board[nx][ny]=='#')
                    continue;

                dist1[nx][ny] = dist1[cur.first][cur.second]+1;
                q1.push({nx, ny});
            }
        }


        while(!q2.empty()){
            pair<int, int> cur = q2.front();
            q2.pop();

            for (int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    cout << dist2[cur.first][cur.second] + 1 << '\n';
                    ispossible = true;
                    break;
                }

                if(board[nx][ny] == '#' || dist2[nx][ny] >= 0)
                    continue;

                if(dist1[nx][ny]!=-1 && dist1[nx][ny] <= dist2[cur.first][cur.second]+1)
                    continue;

                dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
                q2.push({nx, ny});
            }

            if(ispossible){
                break;
            }
        }

        if(!ispossible)
            cout << "IMPOSSIBLE\n";

        ispossible = false;
        
        while(!q1.empty())
            q1.pop();
        
        while(!q2.empty())
            q2.pop();
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> TC;
  for (int testNo = 0; testNo < TC; testNo++) {
    bool escape = false;
    queue<pair<int, int>> Qf = {}, Qs = {};
    cin >> bY >> bX;
    for (int i = 0; i < bX; i++) {
      fill(visF[i], visF[i] + bY, 0);
      fill(visS[i], visS[i] + bY, 0);
    }
    for (int i = 0; i < bX; i++)
      for (int j = 0; j < bY; j++) {
        char c;
        cin >> c;
        if (c == '#') board[i][j] = -1;
        else {
          if (c == '@') {
            Qs.push({i, j});
            visS[i][j] = 1;
          } 
          else if (c == '*') {
            Qf.push({i, j});
            visF[i][j] = 1;
          }
          board[i][j] = 0;
        }
      }
    while (!Qf.empty()) {
      auto v = Qf.front();
      Qf.pop();
      for (int k = 0; k < 4; k++) {
        int nx = v.X + dx[k];
        int ny = v.Y + dy[k];
        if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) continue;
        if (board[nx][ny] == -1) continue;
        if (visF[nx][ny]) continue;
        visF[nx][ny] = visF[v.X][v.Y] + 1;
        Qf.push({nx, ny});
      }
    }
    while ((!Qs.empty()) && (!escape)) {
      auto v = Qs.front();
      Qs.pop();
      for (int k = 0; k < 4; k++) {
        int nx = v.X + dx[k];
        int ny = v.Y + dy[k];
        if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) {
          cout << visS[v.X][v.Y] << '\n';
          escape = true;
          break;
        }
        if (board[nx][ny] == -1) continue;
        if (visS[nx][ny]) continue;
        if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
        visS[nx][ny] = visS[v.X][v.Y] + 1;
        Qs.push({nx, ny});
      }
    }
    if (!escape) cout << "IMPOSSIBLE" << '\n';
  }
}
*/

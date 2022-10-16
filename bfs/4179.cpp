#include<bits/stdc++.h>
using namespace std;

int dist1[1002][1002];
int dist2[1002][1002];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string str[1002];

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        fill(dist1[i], dist1[i] + 1002, -1);
        fill(dist2[i], dist2[i] + 1002, -1);
    }

    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(str[i][j] == 'J'){
                dist2[i][j] = 0;
                q2.push({i, j});
            }

            if(str[i][j] == 'F'){
                dist1[i][j] = 0;
                q1.push({i, j});
            }
        }
    }

    while(!q1.empty()){
        pair<int, int> cur = q1.front();
        q1.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(str[nx][ny] == '#' || dist1[nx][ny]>=0)
                continue;

            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q1.push({nx, ny});
        }
    }

    while(!q2.empty()){
        pair<int, int> cur = q2.front();
        q2.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << dist2[cur.first][cur.second] + 1 << '\n';
                return 0;
            }

            if(str[nx][ny] == '#' || dist2[nx][ny]>=0)
                continue;
            
            if(dist1[nx][ny]!=-1 && dist1[nx][ny] <= dist2[cur.first][cur.second]+1)
                continue;

            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    fill(dist1[i], dist1[i]+m, -1);
    fill(dist2[i], dist2[i]+m, -1);    
  }
  for(int i = 0; i < n; i++)
    cin >> board[i];  
  queue<pair<int,int> > Q1;
  queue<pair<int,int> > Q2;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 'F'){
        Q1.push({i,j});
        dist1[i][j] = 0;        
      }
      if(board[i][j] == 'J'){
        Q2.push({i,j});
        dist2[i][j] = 0;
      }
    }
  }
  
  while(!Q1.empty()){
    auto cur = Q1.front(); Q1.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
      dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
      Q1.push({nx,ny});
    }
  }

  
  while(!Q2.empty()){
    auto cur = Q2.front(); Q2.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){ 
        cout << dist2[cur.X][cur.Y]+1; 
        return 0;
      }
      if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; 
      dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
      Q2.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE"; 

*/
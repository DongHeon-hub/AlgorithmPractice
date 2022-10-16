#include <bits/stdc++.h>
using namespace std;

const int mx = 102;
bool vis[mx][mx];
string board[mx];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;
int n;

void bfs(int x, int y, char ch)
{
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || board[nx][ny] != ch)
                continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r = 0, g = 0, b = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    // 적록 색약이 아닌 사람 개수 구하기

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // R영역
            if (board[i][j] == 'R' && vis[i][j] == 0)
            {
                bfs(i, j, 'R');
                r++;
            }
        }
    }

    // R 구하고 vis 초기화
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // G영역
            if (board[i][j] == 'G' && vis[i][j] == 0)
            {
                bfs(i, j, 'G');
                g++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // B영역
            if (board[i][j] == 'B' && vis[i][j] == 0)
            {
                bfs(i, j, 'B');
                b++;
            }
        }
    }

    cout << r + g + b << ' ';

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);
    r = g = b = 0;

    // 적록 색약인 사람 구하기

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // B영역
            if (board[i][j] == 'B' && vis[i][j] == 0)
            {
                bfs(i, j, 'B');
                b++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    // R, G의 영역

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if(board[i][j] == 'R'){
                board[i][j] = 'G';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            if (board[i][j] == 'G' && vis[i][j] == 0)
            {
                bfs(i, j, 'G');
                g++;
            }
        }
    }

    cout << b + g << '\n';

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
void bfs(int i, int j) {
  queue<pair<int, int>> Q;
  Q.push({ i,j });
  vis[i][j] = 1;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
      vis[nx][ny] = 1;
      Q.push({ nx,ny });
    }
  }
}

int area(){
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j]) {
        cnt++;
        bfs(i, j);
      }
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int not_g = area(); //적록색약이 아닌사람

  // 적록색약인 사람을 구하기위한 방문배열 초기화
  for(int i = 0; i < n; i++)
    fill(vis[i], vis[i]+n, false);
  
  // 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로 바꿔줌
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'G')
        board[i][j] = 'R';
    }
  }

  int is_g = area(); //적록색약인 사람
  cout << not_g << " " << is_g;
  return 0;
}
*/
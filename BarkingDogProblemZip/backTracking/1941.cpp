#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int ans = 0;
int cnt = 0;
vector<char> res;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<pair<int, int>, char> board[30][30];
bool vis[30][30];

bool check(int nx, int ny);
void solve(int k, int x, int y); // k번째 7공주를 정한 상태에서 k+1번째 7공주를 정함.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j].second;
            board[i][j].first.first = i;
            board[i][j].first.second = j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = 1;
            res.push_back(board[i][j].second);
            solve(1, i, j);

            res.pop_back();
            vis[i][j] = 0;
        }
    }
    cout << ans << '\n';
    cout << cnt << '\n';
    return 0;
}

bool check(int nx, int ny)
{
    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
        return false;
    return true;
}

void solve(int k, int x, int y)
{
    if (k == 8)
    {
        cnt++;
        int temp = 0;

        for (int i = 0; i < 7; i++)
            cout << res[i] << ' ';
        cout << '\n';

        for (int i = 0; i < 7; i++)
            if (res[i] == 'S')
                temp++;

        if (temp >= 4)
        {
            ans++;
        }

        return;
    }

    // res.push_back(board[x][y].second);

    // pair<int, int> cur = {x, y};
    // vis[x][y] = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!check(nx, ny))
            continue;

        if (vis[nx][ny] == 1)
            continue;

        vis[nx][ny] = 1;
        res.push_back(board[nx][ny].second);
        solve(k + 1, nx, ny);
        vis[nx][ny] = 0;
        res.pop_back();
    }

    // res.pop_back();
    // vis[x][y] = 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

bool mask[25];
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++)
    cin >> board[i];

  // 25명중 칠공주가 될 사람의 후보 조합을 뽑습니다.
  fill(mask + 7, mask+25, true);
  do {
    queue<pair<int, int>> q;
    // 구성원 중 이다솜파의 수, 가로세로로 인접한 사람의 수
    int dasom = 0, adj = 0;
    bool isp7[5][5] = {}, vis[5][5] = {};
    for (int i = 0; i < 25; i++)
      if (!mask[i]) {
        int x = i / 5, y = i % 5;
        isp7[x][y] = true;
        if (q.empty()) {
          q.push({x, y});
          vis[x][y] = true;
        }
      }
    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.front();
      q.pop();
      adj++;
      dasom += board[x][y] == 'S';
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny])
          continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
    ans += (adj >= 7 && dasom >= 4);

  } while (next_permutation(mask, mask + 25));
  cout << ans;
}

*/

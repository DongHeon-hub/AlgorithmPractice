#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool vis[102][102];
int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int area[100];

queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    int res = 0;

    cin >> m >> n >> k;

    for(int t=0; t<k; t++){
        pair<int, int> left;
        pair<int, int> right;
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        left.X = m - y - 1;
        left.Y = x;

        right.X = m - (h - 1) - 1;
        right.Y = w - 1;

        // 좌표에 대해 영역표시
        for (int i = right.X; i <= left.X; i++){
            for (int j = left.Y; j <= right.Y; j++)
                board[i][j] = 1;
        }


    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(board[i][j] == 0 && vis[i][j]==0){
                int are=0;
                vis[i][j] = 1;
                q.push({i, j});
                
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    are++;
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >=m || ny<0 || ny>=n)
                            continue;
                        
                        if(board[nx][ny] == 1 || vis[nx][ny])
                            continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }


                }

                area[res++] = are;
            }
        }
    }

    sort(area, area + res);

    cout << res << '\n';

    for (int i = 0; i < res; i++)
        cout << area[i] << ' ';

    cout << '\n';

    return 0;
}


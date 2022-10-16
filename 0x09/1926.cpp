#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool Visit[500][500];
int board[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vector<pair<int, int>> v;

    int pic = 0;
    int tmax = 0;
    int max = 0;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j])
                v.push_back({i, j});
        }
    }

    for (int i = 0; i < (int)v.size(); i++){
        if(Visit[v[i].X][v[i].Y])
            continue;
        
        
        Visit[v[i].X][v[i].Y] = 1;
        Q.push({v[i].X, v[i].Y});

        while(!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            tmax++;

            for (int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >=m)
                    continue;
                
                if(Visit[nx][ny] || board[nx][ny]!=1)
                    continue;

                Visit[nx][ny] = 1;
                Q.push({nx, ny});

            }
        }

        pic++;

        if(tmax > max)
            max = tmax;

        tmax = 0;
    }

    cout << pic << '\n'
         << max << '\n';

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int fire[1002][1002];
int dist[1002][1002];
int fo[1002][1002];
string board[1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    int lx, ly;
    bool live = false;

    pair<int, int> f;
    pair<int, int> J;
    queue<pair<int, int>> fQ;
    queue<pair<int, int>> jQ;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
        cin >> board[i];

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(board[i][j] == 'F')
                f = make_pair(i, j);
            
            if(board[i][j] == 'J')
                J= make_pair(i, j);
        }
    }

    if(f == J){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    fo[f.X][f.Y] = 1;
    dist[J.X][J.Y] = 1;
    fQ.push(f);
    jQ.push(J);

    while(!jQ.empty()){
        pair<int, int> cur = fQ.front();
        pair<int, int> jc = jQ.front();
        lx = jc.X;
        ly = jc.Y;
        if(lx == r-1 || ly == c-1)
            break;
        
 
        fQ.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= r || ny < 0 || ny>=c)
                continue;
            
            if(board[nx][ny] == '#' || fo[nx][ny] == 1)
                continue;

            fo[nx][ny] = 1;
            fQ.push({nx, ny});

        }

        for (int dir = 0; dir < 4; dir++){
            int nx_ = jc.X + dx[dir];
            int ny_ = jc.Y + dy[dir];

            if(nx_<0 || nx_>=r || ny_ <0 || ny_ >= c){
                cout << dist[jc.X][jc.Y]+1 << '\n';
                return 0;
            }
                
            
            if(board[nx_][ny_] == '#' || fo[nx_][ny_] == 1 || dist[nx_][ny_])
                continue;

            live = true;
            dist[nx_][ny_] = dist[jc.X][jc.Y] + 1;
            jQ.push({nx_, ny_});
        }

        if(live == false){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        live = false;
    }

    
}
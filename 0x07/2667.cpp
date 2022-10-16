#include<bits/stdc++.h>
using namespace std;

int board[26][26];
bool vis[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> res;
    int ans = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;

            if(c == '\n')
                continue;
            
            if(c == '0')
                continue;

            board[i][j] = 1;
        }
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j < n; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                vis[i][j] = 1;
                q.push({i, j});
                int temp = 0;

                while(!q.empty()){
                    
                    pair<int, int> cur = q.front();
                    q.pop();
                    temp++;
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1)
                            continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                res.push_back(temp);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';

    for(int e : res){
        cout << e << '\n';
    }

    return 0;
}
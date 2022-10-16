#include<bits/stdc++.h>

using namespace std;

int dist[102][102];
string str[102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    
    queue<pair<int, int>> Q;
    dist[0][0] = 0;
    Q.push({0, 0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >=m)
                continue;

            if (str[nx][ny] == '0' || dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1] + 1 << '\n';
    return 0;
}
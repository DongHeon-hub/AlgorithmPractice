#include<bits/stdc++.h>
using namespace std;

int cnt = 0; // cctv의 개수
int ans = INT_MAX; // 감시영역의 최솟값

int n, m;
int cq = 0;
vector<pair<int, int>> dir[6]; // cctv 종류별 방향을 담고 있음.
vector<pair<pair<int, int>, int>> cctv; // cctv의 위치, 종류저장
int board[10][10];
int checkBoard[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // dx, dy는 4번 cctv 처리용. 4방향 체크하면서 dir[4]와 똑같으면 continue
void initDir();                // dir초기화 하는 함수
void solve(int k); // k번째 cctv의 방향에 맞춰서 감시영역을 체크함. 체크한 후에는 체크영역 정상 해제필요
bool check(int nx, int ny); // cctv가 보는 칸이 범위에 있고, 벽이 아닌지. cctv 인지 함수밖에서 체크

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            checkBoard[i][j] = board[i][j];

            // cctv 저장
            if(1<=board[i][j] && board[i][j] <=5){
                cctv.push_back({{i, j}, board[i][j]});
            }

            
        }
    }

    cnt = cctv.size();

    initDir();
    solve(0);

    
    cout << ans << '\n';
    return 0;
}

void initDir(){
    dir[1].push_back({1, 0});
    dir[1].push_back({0, 1});
    dir[1].push_back({-1, 0});
    dir[1].push_back({0, -1});

    dir[2].push_back({1, 0});
    dir[2].push_back({0, 1}); // 방향 2개. 반대로 탐색할 때는 -곱해서

    dir[3].push_back({-1, 0}); // 위 오른쪽
    dir[3].push_back({0, 1});  // 아래 오른쪽
    dir[3].push_back({1, 0});  // 아래 왼쪽
    dir[3].push_back({0, -1}); // 왼쪽 위

    dir[4].push_back({1, 0});
    dir[4].push_back({0, 1});
    dir[4].push_back({0, -1});
    dir[4].push_back({-1, 0});

    dir[5].push_back({0, 0}); // 4방향 다봄.
}

void solve(int k){

    if(k == cnt){
        int temp = 0;

        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){

                if(checkBoard[i][j]==0)
                    temp++;
            }
        }

        ans = min(temp, ans);
        return;
    }

    // cctv 감시영역 백트래킹

    for (int i = 0; i < (int)dir[cctv[k].second].size(); i++){

        if(cctv[k].second==1){
            int nx = cctv[k].first.first;
            int ny = cctv[k].first.second;

            while(check(nx, ny)){
                // 보는 영역이 cctv 가 아닐때만 진행
                if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                    checkBoard[nx][ny]--;
                }

                nx = nx + dir[cctv[k].second][i].first;
                ny = ny + dir[cctv[k].second][i].second;
            }

            solve(k + 1);

            nx = cctv[k].first.first;
            ny = cctv[k].first.second;

            while(check(nx, ny)){
                // 보는 영역이 cctv 가 아닐때만 진행
                if(checkBoard[nx][ny]<0){
                    checkBoard[nx][ny]++;
                }

                nx = nx + dir[cctv[k].second][i].first;
                ny = ny + dir[cctv[k].second][i].second;
            }

        }

        else if(cctv[k].second==2){
            int nx = cctv[k].first.first;
            int ny = cctv[k].first.second;

            while(check(nx, ny)){
                // 보는 영역이 cctv 가 아닐때만 진행
                if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                    checkBoard[nx][ny]--;
                }

                nx = nx + dir[cctv[k].second][i].first;
                ny = ny + dir[cctv[k].second][i].second;
            }

            nx = cctv[k].first.first;
            ny = cctv[k].first.second;

            while(check(nx,ny)){
                if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                    checkBoard[nx][ny]--;
                }

                nx = nx - dir[cctv[k].second][i].first;
                ny = ny - dir[cctv[k].second][i].second;
            }

            solve(k + 1);

            nx = cctv[k].first.first;
            ny = cctv[k].first.second;

            while(check(nx, ny)){
                // 보는 영역이 cctv 가 아닐때만 진행
                if(checkBoard[nx][ny]<0){
                    checkBoard[nx][ny]++;
                }
                nx = nx + dir[cctv[k].second][i].first;
                ny = ny + dir[cctv[k].second][i].second;
            }

            nx = cctv[k].first.first;
            ny = cctv[k].first.second;

            while(check(nx,ny)){
                if(checkBoard[nx][ny]<0){
                    checkBoard[nx][ny]++;
                }

                nx = nx - dir[cctv[k].second][i].first;
                ny = ny - dir[cctv[k].second][i].second;
            }
        }

        else if(cctv[k].second==3){
            if(dir[3][i].first == -1 && dir[3][i].second == 0){
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx -= 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx,ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    ny += 1;
                }

                solve(k + 1);

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    // 보는 영역이 cctv 가 아닐때만 진행
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }
                    nx -= 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx,ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    ny += 1;
                }
            }

            else if(dir[3][i].first == 0 && dir[3][i].second == 1){
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    ny += 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx += 1;
                }

                solve(k + 1);


                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    ny += 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    nx += 1;
                }
            }

            else if(dir[3][i].first == 1 && dir[3][i].second == 0){
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx += 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    ny -= 1;
                }

                solve(k + 1);

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    nx += 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    ny -= 1;
                }
            }

            else{
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx -= 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    ny -= 1;
                }

                solve(k + 1);

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    nx -= 1;
                }

                nx = cctv[k].first.first;
                ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    ny -= 1;
                }
            }
        }

        else if(cctv[k].second==4){
            for (int j = 0; j < 4; j++){
                if(dx[j] == dir[cctv[k].second][i].first && dy[j]==dir[cctv[k].second][i].second)
                    continue;

                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                
                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx = nx + dx[j];
                    ny = ny + dy[j];
                }
            }

            solve(k + 1);

            for (int j = 0; j < 4; j++){
                if(dx[j] == dir[cctv[k].second][i].first && dy[j]==dir[cctv[k].second][i].second)
                    continue;

                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                
                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    nx = nx + dx[j];
                    ny = ny + dy[j];
                }
            }
        }

        else{

            for (int j = 0; j < 4; j++){
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(!(1<=checkBoard[nx][ny] && checkBoard[nx][ny]<=5)){
                        checkBoard[nx][ny]--;
                    }

                    nx = nx + dx[j];
                    ny = ny + dy[j];
                }
            }

            solve(k + 1);

            for (int j = 0; j < 4; j++){
                int nx = cctv[k].first.first;
                int ny = cctv[k].first.second;

                while(check(nx, ny)){
                    if(checkBoard[nx][ny]<0){
                        checkBoard[nx][ny]++;
                    }

                    nx = nx + dx[j];
                    ny = ny + dy[j];
                }
            }
        }
    }
}


bool check(int nx, int ny){
    if(nx < 0 || nx >= n || ny < 0 || ny>=m || board[nx][ny] == 6)
        return false;

    return true;
}
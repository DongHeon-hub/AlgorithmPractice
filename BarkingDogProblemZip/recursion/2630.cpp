#include<bits/stdc++.h>
using namespace std;

int ans[2]; // 하얀색, 파란색 색종이의 개수 저장

bool check(int x, int y, int n); // x, y는 시작 행,열, n은 크기
void solve(int x, int y, int n);
short board[130][130];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    solve(0, 0, n);

    for(auto i : ans)
        cout << i << '\n';

    return 0;
}

bool check(int x, int y, int n){
    short t = board[x][y];

    for (int i = x; i<x+n; i++){
        for (int j = y; j < y + n; j++){
            if(board[i][j] != t)
                return false;
        }
    }

    return true;
}

//왼쪽 위의 점이 x,y 이고 크기가 n*n인 종이에서 몇 개의 색종이가 나올 수 있는지
void solve(int x, int y, int n){
    if(n==1){
        ans[board[x][y]]++;
        return;
    }

    if(check(x, y, n)){
        ans[board[x][y]]++;
        return;
    }

    else{
        n = n / 2;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                solve(x + n * i, y + n * j, n);
            }
        }
    }
}
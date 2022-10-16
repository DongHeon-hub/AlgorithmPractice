#include<bits/stdc++.h>
using namespace std;

int res[2];
int paper[200][200];

// n*n 수열에서 x,y부터 x+n, y+n까지 몇개의 색종이로 돼있는지 구하는 함수

void solve(int n, int x, int y);
bool check(int n, int x, int y);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    }

    solve(n, 0, 0);
    for (int i = 0; i < 2; i++)
        cout << res[i] << '\n';

    return 0;
}

void solve(int n, int x, int y){
    if(n==1){
        res[paper[x][y]]++;
        return;
    }


    if(check(n, x, y)){
        res[paper[x][y]]++;
        return;
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++)
            solve(n / 2, x + i * (n / 2), y + j * (n / 2));
    }
}

bool check(int n, int x, int y){
    int temp = paper[x][y];

    for (int i = x; i < x + n; i++){
        for (int j = y; j < y + n; j++){
            if(paper[i][j] != temp)
                return false;
        }
    }

    return true;
}
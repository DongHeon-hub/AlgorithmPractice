#include<bits/stdc++.h>
using namespace std;

string ans = "";
string video[70];

bool check(int x, int y, int n){
    short t = video[x][y] - '0';

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++){
            if(video[i][j]-'0' != t)
                return false;
        }
    }

    return true;
}


// x, y 를 왼쪽 위의 점으로 하는 n*n 행렬에 대해 압축하는 함수
void solve(int x, int y, int n){
    if(n==1){
        ans.push_back(video[x][y]);
        return;
    }

    if(check(x, y, n)){
        ans.push_back(video[x][y]);
        return;
    }

    // 만약 압축이 안되는 경우

    ans += "(";
    n /= 2;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            solve(x + n * i, y + n * j, n);
        }
    }
    ans += ")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> video[i];

    solve(0, 0, n);

    cout << ans << '\n';
    return 0;
}
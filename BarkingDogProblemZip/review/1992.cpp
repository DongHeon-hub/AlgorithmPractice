#include<bits/stdc++.h>
using namespace std;

int paper[100][100];

void solve(int n, int x, int y);
bool check(int n, int x, int y);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i<n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '0')
                paper[i][j] = 0;
            
            else
                paper[i][j] = 1;
        }
    }

    solve(n, 0, 0);
    cout << '\n';
    return 0;
}

void solve(int n, int x, int y){
    if(n==1){
        cout << paper[x][y];
        return;
    }

    if(check(n, x, y)){
        cout << paper[x][y];
        return;
    }

    cout << '(';

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++)
            solve(n / 2, x + i * (n / 2), y + j * (n / 2));
    }

    cout << ')';
}

bool check(int n, int x, int y)
{
    int temp = paper[x][y];

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (paper[i][j] != temp)
                return false;
        }
    }

    return true;
}
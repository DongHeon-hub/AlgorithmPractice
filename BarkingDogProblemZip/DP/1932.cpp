#include<bits/stdc++.h>
using namespace std;

int board[502][502];
int score[502][502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++)
            cin >> board[i][j];
    }

   
    // 첫번째 열
    score[1][1] = board[1][1];

    for (int i = 2; i <= n; i++)
    {
        score[i][1] = score[i-1][1] + board[i][1];
        score[i][i] = score[i-1][i-1]+board[i][i];
    }

    for (int i = 2; i <= n; i++){
        for (int j = 2; j < i; j++){
            score[i][j] = board[i][j] + max(score[i - 1][j - 1], score[i - 1][j]);
        }
    }

    int ans = score[n][1];

    for (int i = 2; i <= n; i++)
        ans = max(ans, score[n][i]);

    cout << ans << '\n';
    return 0;
}
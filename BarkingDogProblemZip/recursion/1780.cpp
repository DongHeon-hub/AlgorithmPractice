#include <bits/stdc++.h>
using namespace std;

int res[3]; // -1, 0 ,1 개수 저장
int board[2200][2200];

// 3^n * 3^n 행렬과 행, 열 범위에서 -1, 0, 1 로만 이루어진 종이의 수를 파악함.
void func(int n, int r1, int c1, int r2, int c2);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    func(n, 0, 0, n, n);

    for (auto i : res)
        cout << i << '\n';

    return 0;
}

void func(int n, int r1, int c1, int r2, int c2)
{
    
    // Base condition. 해당하는 수를 return 하면 됨
    if (n == 1)
    {
        res[board[r1][c1] + 1]++;
        return;
    }

    bool flag = true;
    int t = board[r1][c1];

    for (int i = r1; i < r2; i++){
        for (int j = c1; j < c2; j++){
            if(board[i][j] != t){
                flag = false;
                break;
            }
        }

        if(!flag)
            break;
    }

    // 만약 종이가 모두 같은 수로 이루어져 있다면
    if(flag){
        res[board[r1][c1] + 1]++;
        return;
    }

    // 만약 종이의 수 중 하나라도 다른 것이 있다면
    int trip = n / 3;

/*
    // 1번
    func(n/3, r1, c1, r1 + trip, c1 + trip);
    // 2번
    func(n/3, r1, c1 + trip, r1 + trip, c1 + 2 * trip);
    // 3번
    func(n/3, r1, c1 + 2 * trip, r1 + trip, c1 + 3 * trip); 
    // 4번
    func(n/3, r1 + trip, c1, r1 + 2 * trip, c1 + trip);
    // 5번
    func(n/3, r1 + trip, c1 + trip, r1 + 2 * trip, c1 + 2 * trip);
    // 6번
    func(n/3, r1 + trip, c1 + 2 * trip, r1 + 2 * trip, c1 + 3 * trip);
    // 7번
    func(n/3, r1 + 2 * trip, c1, r1 + 3 * trip, c1 + trip);
    //8번
    func(n/3, r1 + 2 * trip, c1 + trip, r1 + 3 * trip, c1 + 2 * trip);
    //9번
    func(n/3, r1 + 2 * trip, c1 + 2 * trip, r1 + 3 * trip, c1 + 3 * trip);
*/
    for (int i = 0; i < 3; i++){
        for (int j = 1; j <= 3; j++){
            func(n / 3, r1 + i * trip, c1 + (j-1) * trip, r1 + (i+1) * trip, c1 + j * trip);
        }
    }
}
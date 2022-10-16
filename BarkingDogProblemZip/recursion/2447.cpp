#include<bits/stdc++.h>
using namespace std;



// n에 대해 n*n 정사각형을 패턴에 맞게 paper 에 저장하는 함수
void func(int x, int y, int n);
char paper[2200][2200];
void printPaper(int n);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    func(0, 0, n);
    printPaper(n);
    return 0;
}

void func(int x, int y, int n){
    if(n==3){
        for (int i = x; i < x + 3; i++){
            for (int j = y; j < y + 3; j++){
                if(i != x+1)
                    paper[i][j] = '*';
                else{
                    if(j !=y+1)
                        paper[i][j] = '*';
                    else
                        paper[i][j] = ' ';
                }
            } 
        }
        return;
    }

    n /= 3;

    func(x, y, n);
    func(x, y + n, n);
    func(x, y + 2 * n, n);
    func(x + n, y, n);

    for (int i = x + n; i < x + 2 * n; i++){
        for (int j = y + n; j < y + 2 * n; j++){
            paper[i][j] = ' ';
        }
    }

    func(x + n, y + 2 * n, n);
    func(x + 2 * n, y, n);
    func(x + 2 * n, y + n, n);
    func(x + 2 * n, y + 2 * n, n);

}

void printPaper(int n){
    int i, j;
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++)
            cout << paper[i][j];

        cout << '\n';
    }
}
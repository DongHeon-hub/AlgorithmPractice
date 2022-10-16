#include<bits/stdc++.h>
using namespace std;

int cnt[15][15];

void fillTable();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    int t;

    cin >> t;

    fillTable();
    while(t--){
        cin >> k >> n;
        cout << cnt[k][n] << '\n';
    }
}

void fillTable(){
    for (int j = 1; j < 15; j++)
        cnt[0][j] = j;
    int sum = 0;

    for (int i = 1; i < 15; i++){
        for (int j = 1; j < 15; j++){
            for (int k = 1; k <= j; k++){
                sum += cnt[i-1][k];
            }

            cnt[i][j] = sum;
            sum = 0;
        }
    }
}
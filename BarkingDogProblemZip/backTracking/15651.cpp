#include<bits/stdc++.h>
using namespace std;

int arr[10];

int n, m;
void solve(int k); // 현재까지 k개의 원소가 선택된 상태에서 arr[k]를 정하는 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    solve(0);
    return 0;
}

void solve(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++){
        arr[k] = i;
        solve(k + 1);
    }
}
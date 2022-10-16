#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void solve(int k); // 현재 k개까지 수열의 원소를 선택한 상태에서 arr[k]를 정하는 함수

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

    int st = 1;
    if(k!=0)
        st = arr[k - 1];

    for (int i = st; i <= n; i++){
        arr[k] = i;
        solve(k + 1);
    }
}
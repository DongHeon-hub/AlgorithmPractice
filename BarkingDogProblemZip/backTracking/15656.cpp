#include<bits/stdc++.h>
using namespace std;

int arr[10];
int input[10];
int n, m;
void solve(int k); // k개의 원소까지의 수열의 index를 고른 상태에서 k+1번째 수열 원소의 인덱스를 구함

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input, input + n);
    solve(0);
    return 0;
}

void solve(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << input[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        arr[k] = i;
        solve(k + 1);
    }
}


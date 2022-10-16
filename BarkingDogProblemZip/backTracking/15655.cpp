#include<bits/stdc++.h>
using namespace std;

int arr[10]; // input의 index를 저장하는 수열
int input[10]; // n개의 수 입력
bool isused[10]; // 사용되는지 확인
int n, m;

void solve(int k); //k-1번째 수까지 정한상태에서 k+1번째를 정하는 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    //arr[0] = -1;
    sort(input, input + n);
    //solve(1);
    solve(0);
    return 0;
}

void solve(int k){
    if(k==m+1){
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        if(!isused[i]){
            if(arr[k-1] > input[i])
                continue;

            arr[k] = input[i];
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

/*
void solve(int k){
    if(k==m){
        for(int i=0; i<m; i++) cout << input[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int st = 0;
    if(k!=0) st = arr[k-1]+1;

    for(int i=st; i<n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}
*/
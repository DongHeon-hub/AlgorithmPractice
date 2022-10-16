#include<bits/stdc++.h>
using namespace std;

int arr[10];
bool isused[10];
int n, m;
void solve(int k); // k-1번째 원소까지 선택한 후 arr[k]정를 하는 함수.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    //arr[0] = -1; // 배열의 0번째 원소에 대한 예외처리를 안 하기 위해 arr[0]=-1;
    solve(0);

    //solve(1);
    return 0;
}

void solve(int k){
    if(k==m+1){
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    for (int i = 1; i <=n; i++){
        if(!isused[i]){
            if(arr[k-1] > i)
                continue;

            arr[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

/*
void solve(int k){
    if(k==m){
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st=1;
    if(k!=0) st = arr[k-1]+1;
    for(int i=st; i<=n; i++){
        if(!isused[i]){
            arr[k]=i;
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}

*/
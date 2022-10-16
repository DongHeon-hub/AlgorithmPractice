#include<bits/stdc++.h>
using namespace std;

int arr[10];
int input[10];
int n, m;

void solve(int k);

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

    int st = 0; // 탐색을 시작하는 index. 현재 수열은 오름차순으로 정렬 돼있으므로 k!=0이면
                // k-1번째 원소 인덱스의 다음부터 탐색을 시작해야 한다.
    if(k!=0)
        st = arr[k - 1];

    for (int i = st; i < n; i++){
        arr[k] = i;
        solve(k + 1);
    }
}
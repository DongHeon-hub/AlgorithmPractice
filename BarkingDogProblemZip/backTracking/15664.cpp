#include<bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int input[10];
int arr[10];

void solve(int k); // k개까지의 원소를 선택한 후 arr[k]를 정하는 함수

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

    int st = 0;
    if(k!=0)
        st = arr[k - 1] + 1;

    int temp = 0;
    for (int i = st; i < n; i++){
        if(!isused[i] && temp!=input[i]){
            arr[k] = i;
            isused[i] = 1;
            temp = input[i];
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

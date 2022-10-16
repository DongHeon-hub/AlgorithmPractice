#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int input[10];

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

    int st = arr[k - 1];

    int temp = 0;

    for (int i = st; i<n; i++){
        if(temp!=input[i]){
            temp = input[i];
            arr[k] = i;
            solve(k + 1);
        }
    }
}
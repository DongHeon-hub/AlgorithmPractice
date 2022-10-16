#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n, m;

void func(int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr[0] = -1;
    func(1);
    return 0;
}

void func(int k){
    if(k==m+1){
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    

    for (int i = 1; i <= n; i++){
        if(i >= arr[k-1]){
            arr[k] = i;
            func(k + 1);
        }
    }
}
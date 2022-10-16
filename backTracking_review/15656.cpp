#include<bits/stdc++.h>
using namespace std;

int dat[10];
int arr[10];
int n, m;

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << dat[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        arr[k] = i;
        func(k + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> dat[i];

    sort(dat, dat + n);
    func(0);
    return 0;
}
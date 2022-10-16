#include<bits/stdc++.h>
using namespace std;

int arr[10];
int dat[10];

int n, m;

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << dat[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++){
        if(temp!=dat[i]){
            arr[k] = i;
            temp = dat[i];
            func(k + 1);
        }
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
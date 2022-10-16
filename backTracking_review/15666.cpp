#include<bits/stdc++.h>
using namespace std;

int n, m;
int dat[10];
int arr[10];

void func(int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> dat[i];

    sort(dat, dat + n);

    func(0);
    return 0;
}

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << dat[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;

    for (int i = 0; i < n; i++){
        if(k!=0){
            if(temp!=dat[i] && dat[i] >= dat[arr[k-1]]){
                arr[k] = i;
                temp = dat[i];
                func(k + 1);
            }
        }

        else{
            if(temp!=dat[i]){
                arr[k] = i;
                temp = dat[i];
                func(k + 1);
            }
        }
    }
}
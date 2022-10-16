#include<bits/stdc++.h>
using namespace std;

int dat[10];
int arr[10];
bool isused[10];

int n, m;

void func(int k); // k개의 원소를 선택한 상태에서 arr[k]를 정하는 하뭇

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

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << dat[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}
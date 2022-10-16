#include<bits/stdc++.h>
using namespace std;

bool isused[10];
int arr[10];
int dat[10];
int n, m;

void func(int k); // k번째 원소를 선택한 상태에서 k+1번째 원소를 선택

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

    int temp = 0;

    for (int i = 0; i < n; i++){
        if(!isused[i] && temp!=dat[i]){
            temp = dat[i];
            isused[i] = 1;
            arr[k] = i;
            func(k + 1);
            isused[i] = 0;
        }
    }
}
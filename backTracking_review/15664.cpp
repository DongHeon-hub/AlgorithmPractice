#include<bits/stdc++.h>
using namespace std;

int arr[10];
int dat[10];
bool isused[10];
int n, m;
void func(int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> dat[i];

    sort(dat, dat + n);

    func(0);
    return 0;
}

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++){
            cout << dat[arr[i]] << ' ';
        }

        cout << '\n';
    }

    int temp = 0;
    int st = 0;
    if(k!=0)
        st = arr[k - 1] + 1;

    for (int i = st; i < n; i++){
        if(!isused[i] && temp!=dat[i]){
            arr[k] = i;
            isused[i] = 1;
            temp = dat[i];
            func(k + 1);
            isused[i] = 0;
        }
    }
}
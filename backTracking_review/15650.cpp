#include<bits/stdc++.h>
using namespace std;

bool isused[10];
int arr[10];
int n, m;
void func(int k); 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
    return 0;
}

void func(int k){
    if(k==m){
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st = 1;
    if(k!=0)
        st = arr[k - 1] + 1;

    for (int i = st; i <= n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}


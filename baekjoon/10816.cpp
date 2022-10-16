#include<bits/stdc++.h>
using namespace std;

int arr[20000001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr[t + 10000000]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        cout << arr[t + 10000000] << ' ';
    }

    cout << '\n';
    return 0;
}

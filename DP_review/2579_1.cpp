#include<bits/stdc++.h>
using namespace std;

int d[302];
int a[302];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int sum = 0;

    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }

    d[1] = a[1];
    d[2] = a[2];
    d[3] = a[3];

    for (int i = 4; i <= n; i++)
        d[i] = min(d[i - 2], d[i - 3]) + a[i];

    cout << sum - min(d[n - 1], d[n - 2]) << '\n';
    return 0;
    
}
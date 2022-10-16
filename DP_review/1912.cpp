#include<bits/stdc++.h>
using namespace std;

int d[100002];
int a[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i<=n; i++)
        cin >> a[i];

    d[1] = a[1];

    for (int i = 2; i <= n; i++){
        d[i] = max({d[i - 1] + a[i], a[i - 1] + a[i], a[i]});
    }

    cout << *max_element(d + 1, d + n + 1) << '\n';
    return 0;
}
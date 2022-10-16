#include<bits/stdc++.h>
using namespace std;

int a[52];
int b[52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i] * b[n - i - 1];

    cout << sum << '\n';
    return 0;
}
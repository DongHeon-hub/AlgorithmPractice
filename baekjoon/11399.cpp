#include<bits/stdc++.h>
using namespace std;

int p[1002];
int d[1002];

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);
    int sum = 0;

    d[0] = p[0];
    sum += d[0];

    for (int i = 1; i<n; i++){
        
        d[i] = d[i - 1] + p[i];
        sum += d[i];
    }

    cout << sum << '\n';

    return 0;
}
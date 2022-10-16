#include<bits/stdc++.h>
using namespace std;

int d[100002];
int s[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    d[1] = s[1];

    for (int i = 2; i <= n; i++){
        d[i] = max(s[i], d[i - 1] + s[i]);
    }

    cout << *max_element(d+1, d + n+1) << '\n';
    return 0;
}

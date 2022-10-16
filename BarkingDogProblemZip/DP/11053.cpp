#include<bits/stdc++.h>
using namespace std;

int d[1002];
int s[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> s[i];
        d[i] = 1;
    }

    for (int i = 1; i<n; i++){
        for (int j = 0; j < i; j++){
            if(s[j] >= s[i])
                continue;

            d[i] = max(d[i], d[j] + 1);
        }
    }

    cout << *max_element(d, d + n) << '\n';
    return 0;
}
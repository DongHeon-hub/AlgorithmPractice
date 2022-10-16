#include<bits/stdc++.h>
using namespace std;

long long d[102][10];
const int mx = 1000000000;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    d[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        d[1][i] = 1;

    for (int i = 2; i<=n; i++){
        for (int j = 0; j <= 9; j++){
            if(j!=0)
                d[i][j] = (d[i][j]+d[i-1][j - 1]);
            
            if(j!=9)
                d[i][j] = (d[i][j]+d[i-1][j + 1]);

            d[i][j] %= mx;
        }

        

    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++)
        ans += d[n][i];

    cout << ans << '\n';
    return 0;
}
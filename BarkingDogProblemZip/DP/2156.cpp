#include <bits/stdc++.h>
using namespace std;

int d[10002][3];
int a[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    d[1][1] = a[1];
    d[1][2] = 0;
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];

    for (int i = 3; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j < i-1; j++)
        {
            temp = max({temp, d[j][1], d[j][2]});
        }

        d[i][1] = temp + a[i];
        d[i][2] = d[i - 1][1] + a[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2; j++)
            ans = max(ans, d[i][j]);
    }

    cout << ans << '\n';
    return 0;
}

/*

int main(){
    d[1][1] = a[1];

    for(int i=2; i<=n; i++){
        d[i][0] = max(d[i-1][0], d[i-1][1], d[i-1][2]);
        d[i][1] = d[i-1][0]+a[i];
        d[i][2] = d[i-1][1] + a[i];
    }

    cout << max({d[n][0], d[n][1], d[n][2]});
}
*/
/*
1. 테이블
D[i] = A[1] + ''' + A[i];

2. 점화식

D[k] = R[k] + D[k-1];

이걸 prefix sum 이라고 하며
이걸 잘 알아두길 바란다

*/

#include <bits/stdc++.h>
using namespace std;

int d[100002];
int r[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> r[i];

    d[1] = r[1];

    for (int i = 2; i <= n; i++)
        d[i] = r[i] + d[i - 1];

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        cout << d[y] - d[x - 1] << '\n';
    }
    return 0;
}
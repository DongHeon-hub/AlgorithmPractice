/*
D[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 R
D[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 G
D[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 B

D[k][0] = min(D[k-1][1], D[k-1][2]) +R[k];
D[k][1] = min(D[k-1][0], D[k-1][2]) +G[k];
D[k][2] = min(D[k-1][0], D[k-1][1]) +B[k];

초기값 
D[1][0] = R[1]
D[1][1] = G[1]
D[1][2] = B[1]

*/

#include<bits/stdc++.h>
using namespace std;

int d[1005][3];
int r[1005], g[1005], b[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> r[i] >> g[i] >> b[i];
    }

    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    for (int i = 2; i<=n; i++){
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }

    cout << *min_element(d[n], d[n] + 3);

    return 0;
}
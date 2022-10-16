/*

1. 테이블 정의하기
D[i] = 2*i 크기의 직사각형을 채우는 방법의 수

2. 점화식 찾기
2*1로 덮으면 D[n-1]
1*2로 덮으면 D[n-2]

D[k] = D[k-1]+D[k-2]

3. 초기값 정하기
점화식에서 k-2까지 필요하니, 초기값은 d[1], d[2] 까지 구함
*/

#include<bits/stdc++.h>
using namespace std;

int d[1002];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++){
        d[i] = (d[i - 1] + d[i - 2])%10007;
    }
    cout << d[n] << '\n';

    return 0;
}
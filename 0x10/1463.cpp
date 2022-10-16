/*

1. 테이블 정의하기
D[i]= i 를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값

2. 점화식 찾기
D[k]=?
3으로 나누어지면 3으로 나누거나 (D[k]=D[k/3]+1)
2로 나누어지면 2로 나누거나 (D[k] = D[k/2]+1)
1을 빼거나 (D[k]=D[k-1]+1), 이들 중에서 최솟값

3. 초기값 정의하기
D[1] = 0
*/

#include<bits/stdc++.h>
using namespace std;

int D[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    D[1] = 0;

    for (int i = 2; i <= n; i++){
        D[i] = D[i - 1] + 1;
        if(i%3==0)
            D[i] = min(D[i], D[i / 3] + 1);
        
        if(i%2 == 0)
            D[i] = min(D[i], D[i / 2] + 1);
    }

    cout << D[n] << '\n';
    return 0;
}
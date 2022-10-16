#include<bits/stdc++.h>
using namespace std;

/* 경로 추적
이런 문제를 해결하려면 테이블을 채울 때 추가적인 정보를 어딘가에 기입해야 함.

값 테이블 / 경로 복원용 테이블을 따로 설정해줘야 한다.
*/

int d[1000005];
int pre[1000005];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++){
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;

        if(i%2 == 0 && d[i] > d[i/2]+1){
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }

        if(i%3 == 0 && d[i] > d[i/3]+1){
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << d[n] << '\n';
    int cur = n;
    while(1){
        
            cout << cur << ' ';
            if(cur == 1)
                break;
            cur = pre[cur];
        
    }
}
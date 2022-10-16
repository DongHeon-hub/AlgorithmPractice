#include<bits/stdc++.h>
using namespace std;

// 해시함수에 대해 배울 수 있었다.
// H = sigma(i=0 to n-1)Ai*Ri mod M; (R=31, M=1234567891)

const int R = 31;
const int M = 1234567891;

long long Power(int num){
    long long p = 1;

    for (int i = 0; i < num; i++){
        p *= R;
    }

    return p;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int len;
    long long hash_value=0;

    cin >> len;
    cin >> str;

    for (int i = 0; i<len; i++){
        hash_value += (str[i] - 'a' + 1) * Power(i);
    }

    cout << hash_value % M << '\n';

    return 0;
}
#include<bits/stdc++.h>

using namespace std;


//a^b % m 을 반환해주는 함수
long long mp(long long a, long long b, long long c);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;

    cin >> a >> b >> c;

    cout << mp(a, b, c) << '\n';
    return 0;
}

long long mp(long long a, long long b, long long c){
    if(b == 1){
        return a % c;
    }

    long long val = mp(a, b / 2, c);
    val = val * val % c;

    if(b %2 == 0){
        return val;
    }

    else{
        return (val * (a%c)) % c;
    }
}
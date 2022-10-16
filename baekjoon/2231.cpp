#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int t=1;

    cin >> n;

    while (t < n){
        int temp;
        int res=0;
        temp = t;

        while(temp){
            res += (temp % 10);
            temp /= 10;
        }

        res += t;
        if(res == n){
            cout << t << '\n';
            return 0;
        }

        t++;
    }

    cout << 0 << '\n';
    return 0;
}

//brute-force 알고리즘. 1~n-1까지 돌면서 확인

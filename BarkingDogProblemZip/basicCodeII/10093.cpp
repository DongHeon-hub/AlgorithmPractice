#include<bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long temp;
    long long a, b;
    long long i;


    cin >> a >> b;


    if(a>b){
        temp = a;
        a = b;
        b = temp;
    }

    if(a==b or b==a+1){
        cout << 0;
        return 0;
    }
    cout << b - a - 1 << '\n';

    for (i = a + 1; i < b; i++)
        cout << i << ' ';

    cout << '\n';

    return 0;
}
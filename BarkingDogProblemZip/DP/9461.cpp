#include<bits/stdc++.h>
using namespace std;

long long p[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    p[1] = p[2] = p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    

    for (int i = 6; i <= 100; i++)
        p[i] = p[i - 1] + p[i - 5];

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << p[x] << '\n';

    }

    return 0;
}
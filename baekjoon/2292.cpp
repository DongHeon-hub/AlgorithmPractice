#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ans = 1;
    int cur = 1;
    cin >> n;

    while(n > cur){
        cur = cur + 6 * ans;
        ans++;
    }

    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int t;
    int cur = 1;
    stack<int> S;
    string ans;

    cin >> n;

    while(n--){
        cin >> t;

        while(cur <= t){
            S.push(cur);
            ans += "+\n";
        }

        if (S.top()!=t){
            cout << "NO\n";
            return 0;
        }

        S.pop();
        ans += "-\n";
    }

    cout << ans;

    return 0;
}
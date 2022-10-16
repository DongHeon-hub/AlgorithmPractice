#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int h, w, n;
    int ans = 0;

    cin >> t;
    while(t--){
        cin >> h >> w >> n;

        int modu = n % h;

        if(modu){
            ans += modu * 100 + (n/h) +1;

        }
        else{
            ans += h * 100 + (n/h);
        }

        cout << ans << '\n';
        ans = 0;
    }

    
    return 0;
}
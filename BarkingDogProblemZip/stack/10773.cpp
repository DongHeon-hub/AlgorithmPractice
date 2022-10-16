#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> ST;
    int k;
    int n;
    int res = 0;
    cin >> k;

    while(k--){
        cin >> n;

        if(n){
            res += n;
            ST.push(n);
        }
        else{
            res -= ST.top();
            ST.pop();
        }
    }

    cout << res << '\n';

}

/*

itn k,ans=0;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    while(k--){
        int n;
        cin >> n;
        if(n==0) s.pop();
        else s.push(n);
    }


    // 스택에 있는 모든 값을 더해줌
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    cout << ans;
}

*/

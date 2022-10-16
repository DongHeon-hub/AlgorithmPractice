#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int temp;
pair<int, int> egg[10];
int n;

void solve(int k); // k번째 계란으로 k번째 계란을 제외한 나머지 계란을 칠 때 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> egg[i].first >> egg[i].second;

    solve(0);

    cout << ans << '\n';
    return 0;
}

void solve(int k){
    if(k==n){
        ans = max(ans, temp);
        return;
    }


    if(egg[k].first<=0){
        solve(k + 1);
        return;
    }

    bool flag = false;

    for (int i = 0; i < n;i++){
        if(k==0)
            temp = 0;

        if(i==k || egg[i].first <= 0) // 지금 들고 있는 계란으로는 자기 자신 못깸
            continue;

        flag = true; // 계란을 한번이라도 깸
        int x, y; // k번째 계란의 내구도 , k번째 계란한테 맞는 계란의 내구도
        x = egg[k].first;
        y = egg[i].first;

        egg[k].first -= egg[i].second;
        egg[i].first -= egg[k].second;

        if(egg[k].first <= 0)
            temp++;
        
        if(egg[i].first <= 0)
            temp++;

        solve(k + 1);


        if(egg[k].first<=0)
            temp--;
        if(egg[i].first<=0)
            temp--;
            
        egg[k].first = x;
        egg[i].first = y;
    
    }
    
    if(!flag){
        solve(k + 1);
        return;
    }
}

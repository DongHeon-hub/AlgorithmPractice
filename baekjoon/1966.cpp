#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool cmp(int x, int y){
    return x > y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--){
        int n; // 문서의 수
        int wd; // 원하는 문서의 번호
        int ans = 1;
        int cur = 0;
        vector<int> value;
        queue<pair<int, int>> q;


        cin >> n >> wd;

        for (int i = 0; i<n; i++){
            int x;
            cin >> x;
            q.push({i, x});
            value.push_back(x);
        }

        sort(value.begin(), value.end(), cmp);

        while(!q.empty()){
            if(q.front().Y >= value[cur]){
                if(q.front().X == wd){
                    cout << ans << '\n';
                    break;
                }

                ans++;
                cur++;
                q.pop();
            }

            else{

                q.push(q.front());
                q.pop();
            }
        }
    }

    return 0;
}
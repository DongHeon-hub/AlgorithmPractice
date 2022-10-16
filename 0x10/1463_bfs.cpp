#include <bits/stdc++.h>
using namespace std;

bool check(int x);
int dist[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    if(n==1){
        cout << 0 << '\n';
        return 0;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int arr[3] = {cur * 2, cur * 3, cur + 1};

        for (int i = 0; i < 3; i++){
            if(arr[i] > 1000000)
                continue;
            if(dist[arr[i]]>0)
                continue;
            
            
            if(arr[i] == n){
                cout << dist[cur] + 1 << '\n';
                return 0;
            }

            dist[arr[i]] = dist[cur] + 1;
            q.push(arr[i]);
        }
    }

    return 0;
}
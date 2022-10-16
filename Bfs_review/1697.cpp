#include<bits/stdc++.h>
using namespace std;

int dist[100002];
queue<int> q;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int arr[3];
    cin >> n >> k;
    fill(dist, dist + 100002, -1);

    dist[n] = 0;
    q.push(n);

    if(n==k){
        cout << 0 << '\n';
        return 0;

    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        arr[0] = cur - 1;
        arr[1] = cur + 1;
        arr[2] = 2 * cur;

        for (int i = 0; i < 3; i++){
            if(arr[i] < 0 || arr[i] > 100000)
                continue;
            
            if(arr[i] == k){
                cout << dist[cur] + 1 << '\n';
                return 0;
            }

            if(dist[arr[i]]>=0)
                continue;

            dist[arr[i]] = dist[cur] + 1;
            q.push(arr[i]);
        }
    }

    return 0;
}
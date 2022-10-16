#include<bits/stdc++.h>
using namespace std;


int dist[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int F, S, G, U, D;

    cin >> F >> S >> G >> U >> D;

    fill(dist, dist + F+1, -1);

    dist[S] = 0;
    q.push(S);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int def[2] = {U, -D};

        for (int i = 0; i < 2; i++){
            int nx = cur + def[i];

            // 범위 초과하는 경우
            if(nx < 1 || nx > F)
                continue;
            
            if(dist[nx] >= 0)
                continue;

            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    if(dist[G] == -1){
        cout << "use the stairs\n";
        return 0;
    }

    cout << dist[G] << '\n';
    return 0;
}
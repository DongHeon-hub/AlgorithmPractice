#include<bits/stdc++.h>
using namespace std;

#define MX 100002

int dist[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    fill(dist, dist+MX, -1);
    int ar[3];
    int n, k;

    cin >> n >> k;

    if(n==k){
        cout << 0 << '\n';
        return 0;
    }
    dist[n] = 0;
    Q.push(n);

    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        ar[0] = cur-1; ar[1] = cur+1; ar[2] = 2*cur;

        for(int i=0; i<3; i++){
            if(ar[i] < 0 || ar[i] > 100000) continue;

            if(ar[i] == k){
                cout << dist[cur]+1 << '\n';
                return 0;
            }
            
            if(dist[ar[i]] >= 0) continue;
            

            dist[ar[i]] = dist[cur]+1;
            Q.push(ar[i]);
        }

    }

    return 0;

}

/*
#include<bits/stdc++.h>
using namespace std;

#define MX 200002

int dist[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    fill(dist, dist+MX, -1);
    int ar[3];
    int n, k;

    cin >> n >> k;

    dist[n] = 0;
    Q.push(n);

    while(dist[k] == -1){
        int cur = Q.front();
        Q.pop();
        ar[0] = cur-1; ar[1] = cur+1; ar[2] = 2*cur;

        for(int i=0; i<3; i++){
            if(ar[i] < 0 || ar[i] > 100000) continue;
            if(dist[ar[i]] >= 0) continue;
            

            dist[ar[i]] = dist[cur]+1;
            Q.push(ar[i]);
        }

    }
    
    cout << dist[k] << '\n';

    return 0;

}
*/

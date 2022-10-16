#include<bits/stdc++.h>

using namespace std;

int n;
queue<int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> n;

    for (int i = 1; i <= n; i++)
        Q.push(i);
    
    while(Q.size()!=1){
        Q.pop();
        t = Q.front();
        Q.push(t);
        Q.pop();
    }

    cout << Q.front();
    return 0;
}
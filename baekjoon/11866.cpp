#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    vector<int> v;
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        q.push(i + 1);
    
    while(!q.empty()){

        for (int i = 0; i < k - 1; i++){
            q.push(q.front());
            q.pop();
        }

        v.push_back(q.front());
        q.pop();
    }

    cout << '<';

    for (vector<int>::iterator it = v.begin(); it != v.end() - 1; it++){
        cout << *it << ',' << ' ';
    }

    cout << *(v.end() - 1) << '>' << '\n';
    return 0;
}
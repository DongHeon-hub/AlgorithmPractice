#include<bits/stdc++.h>

using namespace std;

deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int size;
    int res = 0;

    cin >> n >> m;

    size = n;

    for (int i = 0; i < n; i++)
        dq.push_back(i + 1);
    
    while(m--){
        int t;
        int idx;
        cin >> t;

        idx = find(dq.begin(), dq.end(), t) - dq.begin();

        // deque 왼쪽으로 옮기는게 최소

        if(idx < size-idx){
            while(dq.front() != t){
                dq.push_back(dq.front());
                dq.pop_front();
                res++;
            }

            dq.pop_front();
        }

        // deque 오른쪽으로 옮기는게 최소
        else{
            while(dq.front()!= t){
                dq.push_front(dq.back());
                dq.pop_back();
                res++;
            }

            dq.pop_front();
        }
    }

    cout << res << '\n';
    return 0;
}

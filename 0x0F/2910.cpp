#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v;
    int n, c;

    cin >> n >> c;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        bool che = true;

        for(auto& e : v){
            if(e.second == x){
                e.first++;
                che = false;
                break;
            }
        }

        // 기존 원소에 없는 경우
        if(che){
            v.push_back({1, x});
        }
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(auto e : v){
        for (int i = 0; i < e.first; i++)
            cout << e.second << ' ';

    }

    return 0;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first > b.first;
}
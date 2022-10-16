#include<bits/stdc++.h>
using namespace std;

int n, m;
int l[1000002];

bool solve(int x); // 절단기의 높이가 x일때 m 이상의 나무를 가져갈 수 있냐?

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> l[i];

    int st = 0;
    int en = *max_element(l, l + n);

    while(st < en){
        int mid = (st + en + 1) / 2;

        if(solve(mid))
            st = mid;
        
        else
            en = mid - 1;
    }

    cout << st << '\n';
    return 0;
}

bool solve(int x){
    long long cur = 0;

    for (int i = 0; i<n; i++)
        cur += (l[i] - x > 0 ? l[i] - x : 0);

    return cur >= m;
}
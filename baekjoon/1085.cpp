#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, w, h;
    int m1, m2;

    cin >> x >> y >> w >> h;

    m1 = min(y, h - y);
    m2 = min(x, w - x);
    cout << min(m1, m2) << '\n';

    return 0;
}
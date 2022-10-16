#include<bits/stdc++.h>
using namespace std;

int a[500005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    cin >> m;

    while(m--){
        int x;
        cin >> x;

        if(binary_search(a, a+n, x))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}
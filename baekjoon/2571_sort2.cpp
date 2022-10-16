#include<bits/stdc++.h>
using namespace std;

bool isExist[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int t;
    for(int i=0; i<n; i++){
        cin >> t;

        isExist[t + 1000000] = true;
    }

    for (int i = 0; i <= 2000000; i++){
        if(isExist[i])
            cout << i - 1000000 << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        for (int j = 1; j <= i - 1; j++)
            cout << ' ';

        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
            cout << '*';

        cout << '\n';
    }

    return 0;
}

/*

    for(int i=n; i>=1; i--){
        for(int j=1; i<=n-i; j++) cout << ' ';

        for(int j=1; i<=2*i-1; j++) cout << '*';
    }

    */
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n1, n2, n3;
    int max;
    cin >> n1 >> n2 >> n3;

    if(n1==n2 && n2==n3){
        cout << 10000 + n1 * 1000 << '\n';
    }

    else if(n1==n2 || n2==n3 || n1==n3){
        if(n1==n2){
            cout << 1000 + n2 * 100 << '\n';
        }

        else{
            cout << 1000 + n3 * 100 << '\n';
        }
    }

    else{
        max = (n1 < n2) ? (n2 < n3 ? n3 : n2) : (n1 < n3 ? n3 : n1);

        cout << max * 100 << '\n';
    }

    return 0;
}

/* 별해 코드


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[3];

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);

    if(a[0] == a[2]) cout << 10000 + a[0]*1000; // 세수가 동일
    else if(a[0] == a[1] || a[1] == a[2]) 1000+a[1]*100; // 두 수가 동일
    else cout << a[2]*100;


}

*/
#include<bits/stdc++.h>
using namespace std;

bool arr[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    while(n--){
        int num;
        cin >> num;
        arr[num + 1000000]=1;
    }

    for (int i = 2000000; i >= 0; i--){
        if(arr[i]){
            cout << i - 1000000 << '\n';
        }
    }

    return 0;
}
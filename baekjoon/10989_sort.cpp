#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10000] = {};

    int n;
    int num;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num;

        arr[num - 1]++;
    }

    for (int i = 0; i < 10000; i++){
        if(arr[i] != 0){
            for (int j = 0; j < arr[i]; j++)
                cout << i + 1 << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    int max, max_index=1;

    for(int i=0; i<9; i++)
        cin >> arr[i];

    max = arr[0];

    for (int i = 1; i < 9; i++){
        if(max < arr[i]){
            max = arr[i];
            max_index = i+1;
        }
    }

    cout << max << '\n'
         << max_index << '\n';

    return 0;
}
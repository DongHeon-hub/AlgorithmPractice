#include<bits/stdc++.h>
using namespace std;

int arr[101] = {};

    

int fib(int n){

    for (int i = 0; i <= n; i++){
        if(i==0 || i==1){
            
            arr[i] = 1;
            continue;
        }

        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main(){
    int n;
    cin >> n;

    cout << fib(n) << '\n';
    return 0;
}
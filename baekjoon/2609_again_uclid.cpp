#include<bits/stdc++.h>

using namespace std;

void Swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a, int b){
    int r;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if(a < b)
        Swap(&a, &b);

    cout << gcd(a, b) << '\n'
         << (a * b) / gcd(a, b) << '\n';

    return 0;
}
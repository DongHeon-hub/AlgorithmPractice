#include<bits/stdc++.h>

using namespace std;

const int mx = 100005;

int dat[mx];
int pos = 0;

void push(int num){
    dat[pos++] = num;
}

void pop(){
    pos--;
}

int Top(){
    return dat[pos - 1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    int n;
    int res = 0;

    cin >> k;

    while(k--){
        cin >> n;
        if(n){
            res += n;
            push(n);
        }

        else{
            res -= Top();
            pop();
        }
    }

    cout << res << '\n';
}
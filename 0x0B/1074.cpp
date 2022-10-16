#include<bits/stdc++.h>
using namespace std;

//2^n * 2^n 행렬에서 r,c를 몇번째로 방문하는지
int vis(int n, int r, int c);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    cout << vis(n, r, c) << '\n';
    return 0;
}

int vis(int n, int r, int c){
    if(n==0){
        return 0;
    }

    int half = (1 << (n - 1));

    if(r < half && c < half){
        return vis(n - 1, r, c);
    }

    else if(r < half && c >= half){
        return half * half + vis(n - 1, r, c - half);
    }

    else if(r>=half && c<half){
        return 2 * half * half + vis(n - 1, r - half, c);
    }

    else{
        return 3 * half * half + vis(n - 1, r - half, c - half);
    }
}
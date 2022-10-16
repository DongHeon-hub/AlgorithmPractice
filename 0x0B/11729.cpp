#include<bits/stdc++.h>
using namespace std;

/*
n-1개의 원판을 기둥 1에서 기둥 2로 옮긴다.
n번 원판을 기둥 1 에서 기둥 3으로 옮긴다.
n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다.

원판이 1개일 때는 내가 원하는 곳으로 옮길 수 있다.
원판이 k개일때 옮길 수 있으면 원판이 k+1개일 때도 옮길수 있다.

1. 함수의 정의
i) void func(int n) 원판 n개를 기둥 1에서 기둥 3으로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n) 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수

2. Base condition
n=1 일때 cout << a << ' ' << b << '\n';

3. 재귀 식
n-1 개의 원판을 기둥 a 에서 기둥 6-a-b로 옮긴다.
n번 원판을 기둥 a에서 기둥 b로 옮긴다.
n-1 개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.

-> func(a, 6-a-b, n-1);
   cout << a << ' ' << b << '\n';
   func(6-a-b, b, n-1);

*/

void func(int a, int b, int n);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    cout << (1<<n) - 1 << '\n';
    func(1, 3, n);
    return 0;
}

void func(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }

    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}
#include<iostream>
using namespace std; // 어떤 멤버를 사용할 때 따로 소속을 알리지 않아도 std 라이브러리에 포함된 것으로 간주하게 됨.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    int num;
    cin >> n >> x;
    
    while(n--){
        cin >> num;

        if(num < x)
            cout << num << " ";
    }

    return 0;
}
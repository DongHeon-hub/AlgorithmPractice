#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min=100;
    int input;
    int sum = 0;

    for (int i = 0; i < 7; i++){
        cin >> input;

        if(input%2 != 0){
            sum += input;
            if(input < min)
                min = input;
        }
    }

    if(min==100)
        cout << -1;
    else
        cout << sum << '\n' << min << '\n';

    return 0;
}
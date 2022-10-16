#include<bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int num[15];
bool isused[15];

void func(int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        cin >> n;
        if(n==0)
            break;

        for (int i = 0; i < n; i++)
            cin >> num[i];

        func(0);
        cout << '\n';

    }
    return 0;
}

void func(int k){
    if(k==6){
        bool flag = true;
        int tmp = -1;

        for (int i = 0; i < 6; i++){
            if(tmp > num[arr[i]])
                flag = false;

            tmp = num[arr[i]];
        }

        if(flag){
            for (int i = 0; i < 6; i++)
                cout << num[arr[i]] << ' ';
            cout << '\n';
        }

        return;
    }

    for (int i = 0; i < n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}
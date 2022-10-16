#include<bits/stdc++.h>
using namespace std;

int dat[20];
bool isused[20];
vector<int> arr;
int k;

void func(int t); //t번째 원소를 고른상태에서 t+1번째 원소를 정하는 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(true){
    
        cin >> k;

        if(k==0)
            break;

        for (int i = 0; i < k; i++)
            cin >> dat[i];

    
        func(0);
        
        arr.clear();
        cout << '\n';
    }

    return 0;
}

void func(int t){
    if(t==k){
        if((int)arr.size() == 6){
            for (int i = 0; i < 6; i++)
                cout << dat[arr[i]] << ' ';
            cout << '\n';
            return;
        }

        return;
    }

    if((int)arr.size() == 6){
        for (int i = 0; i < 6; i++)
            cout << dat[arr[i]] << ' ';

        cout << '\n';
        return;
    }

    arr.push_back(t);
    func(t + 1);
    arr.pop_back();

    func(t + 1);
}
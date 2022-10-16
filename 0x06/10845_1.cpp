#include<bits/stdc++.h>

using namespace std;

const int mx = 10001;
int dat[mx];
int head = 0, tail = 0;

void push(int num){
    dat[tail++] = num;
}

void pop(){
    head++;
}

int Front(){
    return dat[head];
}

int Back(){
    return dat[tail - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;

    cin >> n;

    while(n--){
        cin >> str;

        if(str=="push"){
            int num;
            cin >> num;
            push(num);
        }

        else if(str=="pop"){
            if(tail-head){
                cout << dat[head] << '\n';
                pop();
            } else
                cout << -1 << '\n';
        }

        else if(str=="size"){
            cout << tail - head << '\n';
        }

        else if(str=="empty"){
            if(tail-head)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }

        else if(str=="front"){
            if(tail-head)
                cout << Front() << '\n';
            else
                cout << -1 << '\n';
        }

        else{
           if(tail-head)
               cout << Back() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
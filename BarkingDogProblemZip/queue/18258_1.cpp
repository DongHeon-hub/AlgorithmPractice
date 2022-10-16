#include<bits/stdc++.h>

using namespace std;

const int mx = 2000005;
int dat[mx];
int head = 0, tail = 0;

void push(int num){
    dat[tail++] = num;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
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

        if(str == "push"){
            int t;
            cin >> t;
            push(t);
        }

        else if(str == "pop"){
            if(head==tail)
                cout << -1 << '\n';
            else{
                cout << front() << '\n';
                pop();
            }
        }

        else if(str == "size"){
            cout << tail - head << '\n';
        }

        else if(str == "empty"){
            if(head==tail)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }

        else if(str == "front"){
            if(head==tail)
                cout << -1 << '\n';
            else
                cout << front() << '\n';
        }

        else{
            if(head==tail)
                cout << -1 << '\n';
            else
                cout << back() << '\n';
        }
    }
}
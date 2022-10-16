#include<bits/stdc++.h>

using namespace std;

const int mx = 1000005;
int dat[2 * mx + 1];
int head = mx, tail = mx;

void push_front(int num){
    dat[--head] = num;
}

void push_back(int num){
    dat[tail++] = num;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
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

    string str;
    int m;

    cin >> m;

    while(m--){
        cin >> str;

        if(str == "push_front"){
            int n;
            cin >> n;
            push_front(n);
        }

        else if(str == "push_back"){
            int n;
            cin >> n;
            push_back(n);
        }

        else if(str == "pop_front"){
            if(tail-head==0)
                cout << -1 << '\n';
            else{
                cout << front() << '\n';
                pop_front();
            }
        }

        else if(str == "pop_back"){
            if(tail-head==0)
                cout << -1 << '\n';
            else{
                cout << back() << '\n';
                pop_back();
            }
        }

        else if(str == "size"){
            cout << tail - head << '\n';
        }

        else if(str== "empty"){
            if(tail-head)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }

        else if(str == "front"){
            if(head!=tail)
                cout << front() << '\n';
            else
                cout << -1 << '\n';
        }

        else if(str == "back")
            if(head!=tail)
                cout << back() << '\n';
            else
                cout << -1 << '\n';
        }
}

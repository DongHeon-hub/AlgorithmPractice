#include<bits/stdc++.h>
using namespace std;

const int mx = 100001;

int dat[mx];
int top = 0;
int s = 0;

void push(int num){
    dat[top++] = num;
    s++;
}

int pop(){
    if(s!=0){
        s--;
        return dat[--top];
    } else
        return -1;
}

int Size(){
    return s;
}

int isEmpty(){
    if(s)
        return 0;
    else
        return 1;
}

int Top(){
    if(s)
        return dat[top - 1];
    else
        return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;

    while(n--){
        cin >> s;

        if(s.compare("push") == 0){
            int num;
            cin >> num;
            push(num);
        }

        else if(s.compare("pop") == 0){
            cout << pop() << '\n';
        }

        else if(s.compare("size")==0){
            cout << Size() << '\n';
        }

        else if(s.compare("empty") == 0){
            cout << isEmpty() << '\n';
        }

        else
            cout << Top() << '\n';
    }

    return 0;
}

// string의 비교는 compare 함수를 사용한다.
// string seven_war = "임진왜란"
// string korea_war = "한국전쟁"

// if(seven_war.compare(korea_war)) 다른 문자열 입니다
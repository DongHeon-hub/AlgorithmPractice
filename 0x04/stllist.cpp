#include<bits/stdc++.h>

using namespace std;

int main(){
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값 출력. 1을 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; // t를 앞으로 1칸 전진. t는 현재 2를 가리키고 있음.
    t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                    // 10 6 1 5 현재 t는 5를 가리키고 있음



    bool istrue = (t == L.end());
    cout << "istrue?:" << istrue << '\n';

    cout << *t << '\n';
    for (list<int>::iterator it = L.begin(); it != L.end(); it++){
        cout << *it;
        cout << ' ';
    }

    cout << '\n';
    

    L.front() = 6;
    L.back() = 2;

    for (list<int>::iterator it = L.begin(); it != L.end(); it++){
        cout << *it;
        cout << ' ';
    }

    cout << '\n'
         << L.empty();

    cout << '\n'
         << L.size();

    return 0;
}
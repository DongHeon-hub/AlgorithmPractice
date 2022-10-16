#include<bits/stdc++.h>

using namespace std;

int main(){
    deque<int> DQ;
    DQ.push_front(10); // 10
    DQ.push_back(50); // 10 50
    DQ.push_front(24); // 24 10 50
    for (deque<int>::iterator it = DQ.begin(); it != DQ.end(); it++){
        cout << *it;
    }

    cout << '\n';
    cout << DQ.size() << '\n'; // 3
    if(DQ.empty())
        cout << "DQ is empty\n";
    else
        cout << "DQ is not empty\n";

    DQ.pop_front(); // 10 25
    DQ.pop_back(); // 10

    cout << DQ.back() << '\n'; // 10
    DQ.push_back(72); // 10 72
    cout << DQ.front() << '\n'; //10
    DQ.push_back(12); // 10 72 12
    DQ[2] = 18; // 10 72 18
    DQ.insert(DQ.begin() + 1, 33); //10 33 72 18
    DQ.insert(DQ.begin() + 4, 60); // 10 33 72 18 60
    for(auto x : DQ)
        cout << x << ' ';
    cout << '\n';
    DQ.erase(DQ.begin() + 3); // 10 33 72 60
    cout << DQ[3] << '\n'; // 60
    DQ.clear();

    return 0;
}

// c++ deque vs vector 찾아보기
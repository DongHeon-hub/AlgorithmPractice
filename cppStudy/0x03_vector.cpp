#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v1(3, 5);
    cout << v1.size() << '\n';
    v1.push_back(7);

    vector<int> v2(2);
    v2.insert(v2.begin() + 1, 3); // {0,3,0};

    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin() + 2); // {1,2,4};

    vector<int> v4;

    v4 = v3; // {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n'; // 124;
    v4.pop_back(); // {1,2}
    v4.clear();

    cout << v3[1];

    return 0;
}


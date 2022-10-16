#include<bits/stdc++.h>
using namespace std;

queue<pair<int, string>> q[201];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int age;
        string name;

        cin >> age >> name;

        q[age].push({age, name});
    }

    for (int i = 1; i <=200; i++){
        if(q[i].empty())
            continue;
        
        while(!q[i].empty()){
            cout << q[i].front().first << ' ' << q[i].front().second << '\n';
            q[i].pop();
        }
    }

    return 0;
}

/*

int main(){
    int n;
    cin >> n;
    vector<string> list[201];

    while(n--){
        string name;
        int age;
        cin >> age >> name;

        list[age].push_back(name);
    }
}

*/
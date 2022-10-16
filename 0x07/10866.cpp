#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int m;
    deque<int> DQ;

    cin >> m;

    while(m--){
        cin >> str;

        if(str == "push_front"){
            int n;
            cin >> n;
            DQ.push_front(n);
        }

        else if(str == "push_back"){
            int n;
            cin >> n;
            DQ.push_back(n);
        }


        else if(str == "pop_front"){
            if(DQ.empty())
                cout << -1 << '\n';
            else{
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }

        else if(str == "pop_back"){
            if(DQ.empty())
                cout << -1 << '\n';
            else{
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }

        else if(str == "size"){
            cout << DQ.size() << '\n';
        }

        else if(str=="empty"){
            cout << (int)DQ.empty() << '\n';
        }
        
        else if(str=="front"){
            if(DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.front() << '\n';
        }

        else if(str == "back"){
            if(DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.back() << '\n';
        }
    }

    return 0;
}
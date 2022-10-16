#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    string str;

    int n;
    cin >> n;

    while(n--){
        cin >> str;

        if(str.compare("push")==0){
            int num;
            cin >> num;
            s.push(num);
        }

        else if(str.compare("pop")==0){
            if(s.empty() == 0){
            cout << s.top() << '\n';
            s.pop();
            }
            else
                cout << -1 << '\n';
        }

        else if(str.compare("size")==0){
            cout << s.size() << '\n';
        }

        else if(str.compare("empty")==0){
            cout << s.empty() << '\n';
        }

        else{
            if(s.empty() == 0)
                cout << s.top() << '\n';

            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string str;

    while(t--){
        stack<char> s;
        cin >> str;
        bool flag = true;

        for(char c : str){
            if(c == '(')
                s.push(c);
            else{
                if(s.empty()){
                    cout << "NO\n";
                    flag = false;
                    break;
                }

                s.pop();
            }
        }

        if(flag && !s.empty()){
            cout << "NO\n";
            continue;
        }

        if(flag){
            cout << "YES\n";
            
        }
    }
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    list<char> str;
    list<char>::iterator it;
    int m;
    char cmd, ch;

    for (string::iterator i=s.begin(); i != s.end(); i++){
        str.push_back(*i);
    }

    it = str.end();

    cin >> m;

    while(m--){
        cin >> cmd;

        if(cmd == 'P'){
            cin >> ch;
            str.insert(it, ch);
        }

        else if(cmd == 'L'){
            if(it!=str.begin())
                it--;
        }

        else if(cmd == 'D'){
            if(it!=str.end())
                it++;
        }

        else{
            if(it!=str.begin()){
                it--;
                it = str.erase(it);
            }
        }
    }

    for (list<char>::iterator ch = str.begin(); ch != str.end(); ch++){
        cout << *ch;
    }

    cout << '\n';
    return 0;
}




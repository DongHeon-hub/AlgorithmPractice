#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    string str;

    cin >> str;

    for (string::iterator it=str.begin(); it!=str.end(); it++){
        string app="";
        
        for (string::iterator tmp = it; tmp!=str.end(); tmp++)
            app += *tmp;

        v.push_back(app);
    }

    sort(v.begin(), v.end());

    for(auto e : v)
        cout << e << '\n';

    return 0;
}

/*

string st;
vector<string> v;

cin >> st;

int stringlen = st.length();

for(int i=0; i<stringlen; i++){
    string temp = st.substr(i);
    v.push_back(temp);
}
*/
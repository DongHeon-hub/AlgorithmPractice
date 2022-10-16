#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[26] = {};
    int result = 0;

    string s1, s2;

    cin >> s1 >> s2;

    for(auto c : s1)
        a[c - 'a']++;

    for(auto c : s2)
        a[c - 'a']--;

    for (int i : a) if(i!=0)
            result += abs(i);

    cout << result << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
string st[20002];

bool cmp(const string &a, const string &b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    
    else{
        return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> st[i];

    sort(st, st + n, cmp);


    cout << st[0] << '\n';

    for (int i = 1; i < n; i++){
        if(st[i-1]!=st[i])
            cout << st[i] << '\n';
    }

        return 0;
}
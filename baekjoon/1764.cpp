#include<bits/stdc++.h>
using namespace std;

string a[500002];
string b[500002];
vector<string> v;

int n, m;

bool bsearch(string x);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0; i < n; i++){
        if(bsearch(a[i])){
            ans++;
            v.push_back(a[i]);
        }
    }

    cout << ans << '\n';
    for(auto s : v)
        cout << s << '\n';

    return 0;
}

bool bsearch(string x){
    int left = 0;
    int right = m - 1;

    while(left <= right){
        int middle = left + (right - left) / 2;

        if(x == b[middle]){
            return true;
        }

        if(b[middle].compare(x) < 0)
            left = middle + 1;
        
        else
            right = middle - 1;
    }

    return false;
}
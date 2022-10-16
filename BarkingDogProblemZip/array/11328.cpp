#include<bits/stdc++.h>

using namespace std;

bool check(char *a, char *b);

int ac[26] = {};
int bc[26] = {};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char a[1001], b[1001];

    cin >> n;

    while(n--){
        cin >> a >> b;
        
        if(check(a,b))
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';

        for (int i = 0; i < 26; i++)
            ac[i] = bc[i] = 0;
    }

    return 0;
}

bool check(char*a, char*b){
    if(strlen(a) != strlen(b))
        return false;

    int len = strlen(a);

    for (int i = 0; i < len; i++){
        ac[a[i] - 'a']++;
        bc[b[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) if(ac[i]!=bc[i])
            return false;

    return true;
}
/*

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int a[26]={};
        string s1 ,s2;
        cin >> s1 >> s2;

        for(auto c : s1) a[c-'a']++;
        for(auto c : s2) a[c-'a']--;

    }

    bool isPossible = true;

    for(int i : a){
        if(i!=0) isPossible = false;
    }

    if(isPossible) cout << "Possible" << '\n';
    else cout << "Impossible" << '\n';

    return 0;
}

*/
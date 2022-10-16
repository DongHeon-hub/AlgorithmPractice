#include <bits/stdc++.h>
using namespace std;

/*
hash, map을 이용해서 푸는 방법이 있다.
*/
string name[100002];
pair<string, int> p[100002];

void binary_Search(string x, int n);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
        p[i].first = name[i];
        p[i].second = i + 1;
    }

    sort(p, p + n);

    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;

        if ('A' <= x[0] && x[0] <= 'Z')
        {
            binary_Search(x, n);
        }

        else
            cout << name[stoi(x) - 1] << '\n';
    }

    return 0;
}

void binary_Search(string x, int n){
    int left = 0;
    int right = n - 1;

    while(left<=right){
        int middle = left + (right - left) / 2;

        if(p[middle].first == x){
            cout << p[middle].second << '\n';
            return;
        }

        if(p[middle].first.compare(x) < 0){
            left = middle + 1;
        }

        else{
            right = middle - 1;
        }
    }
}
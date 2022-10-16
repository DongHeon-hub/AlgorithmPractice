#include <bits/stdc++.h>
using namespace std;

pair<int, int> tim[100002]; // 시작 시간 / 끝나는 시간
int n;
int ans = 0;
int t = 0; // 현재 시간

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tim[i].first >> tim[i].second;
       
    }

    sort(tim, tim + n, cmp);

    
    for (int i = 0; i < n; i++)
    {
        if (t > tim[i].first)
            continue;

        else
        {
            t = tim[i].second;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int m, n;
int l[1000005];

bool solve(int x); // 길이가 x인 막대를 m명의 조카에게 나눠줄 수 있냐?

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
        cin >> l[i];

    int st = 0;
    int en = 1000000000;

    while (st < en)
    {
        int mid = (st + en + 1) / 2;
        cout << st << ' ' << mid << ' ' << en << '\n';
        if (solve(mid))
        {
            st = mid;
           
        }

        else
            en = mid - 1;
    }

    cout << st << '\n';
    
    return 0;
}

bool solve(int x)
{
    long long cur = 0;

    for (int i = 0; i < n; i++)
        cur += (l[i] / x);

    return cur >= m;
}
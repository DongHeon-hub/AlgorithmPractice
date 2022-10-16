#include <bits/stdc++.h>
using namespace std;

int d[1005];
int s[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    d[1] = s[1];

    for (int i = 2; i <= n; i++)
    {
        d[i] = s[i];

        for (int j = 1; j < i; j++)
        {
            if (s[j] >= s[i])
                continue;

            d[i] = max(d[i], d[j] + s[i]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ' << '\n';
    cout << *max_element(d + 1, d + n + 1) << '\n';

    return 0;
}
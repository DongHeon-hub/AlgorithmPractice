#include <bits/stdc++.h>
using namespace std;

int d[502][502];
int score[502][502];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> score[i][j];
        }
    }

    d[1][1] = score[1][1];

    for (int i = 2; i <= n; i++)
    {
        d[i][1] = d[i - 1][1] + score[i][1];
        d[i][i] = d[i - 1][i - 1] + score[i][i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + score[i][j];
        }
    }

    int ans = d[n][1];

    cout << *max_element(d[n] + 1, d[n] + n + 1) << '\n';
    return 0;
}

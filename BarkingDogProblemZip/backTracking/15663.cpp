#include <bits/stdc++.h>
using namespace std;

int arr[10];
int isused[10];

int input[10];
int save[40100][10];
int n, m;
int cnt = 0;
void solve(int k);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input, input + n);
    solve(0);
    return 0;
}

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i<m; i++)
            cout << input[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isused[i] && temp!=input[i])
        {
            arr[k] = i;
            temp = input[i];
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

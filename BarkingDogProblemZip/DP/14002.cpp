#include <bits/stdc++.h>
using namespace std;

int a[1002];
int pre[1002];
int d[1002]; // d[i] = i번째 수까지 가장 긴 증가하는 부분 수열의 길이
int arr[1002];
int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    fill(d + 1, d + n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j] >= a[i])
                continue;

            if (d[i] <= d[j])
            {
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    }

    int idx = max_element(d + 1, d + n + 1) - d;
    deque<int> dq;

    while(idx){
        dq.push_front(a[idx]);
        idx = pre[idx];
    }

    cout << dq.size() << '\n';
    for(auto e : dq)
        cout << e << ' ';

    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    queue<int> q;
    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << '\n';
        return 0;
    }

    fill(dist, dist + 100002, -1);

    dist[n] = 0;
    q.push(n);

    if (n != 0)
    {
        for (int i = n * 2; i <= 100000; i *= 2)
        {

            if (i == k)
            {
                cout << 0 << '\n';
                return 0;
            }

            dist[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int dir[2] = {-1, 1};

        for (int i = 0; i < 2; i++)
        {
            int nx = cur + dir[i];

            if (nx == k)
            {
                cout << dist[cur] + 1 << '\n';
                return 0;
            }

            if (nx <= 0 || nx > 100000)
                continue;

            if (dist[nx] >= 0)
                continue;

            dist[nx] = dist[cur] + 1;
            q.push(nx);

            for (int j = nx * 2; j <= 100000; j *= 2)
            {
                if (j == k)
                {
                    cout << dist[nx] << '\n';
                    return 0;
                }

                if (dist[j] >= 0)
                    continue;

                dist[j] = dist[nx];
                q.push(j);
            }
        }
    }
}
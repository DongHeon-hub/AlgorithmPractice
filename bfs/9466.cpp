#include <bits/stdc++.h>
using namespace std;


int wish[100002];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n;

    cin >> t;

    while (t--)
    {
        int ans = 0;
        cin >> n;
        bool check[100002];
        bool vis[100002];
        queue<pair<int, int>> q;

        for (int i = 1; i <= n; i++)
        {
            int w;
            cin >> w;

            wish[i] = w;
        }

        fill(check+1, check + n+1, false);
        fill(vis+1, vis + n+1, false);

        for (int i = 1; i <= n; i++)
        {
           
            if (vis[i] == 0)
            {

                if (vis[wish[i]])
                {
                    check[i] = 1;
                    vis[i] = 1;
                    ans++;
                    continue;
                }

                vis[i] = 1;
                q.push({i, wish[i]});

                while (!q.empty())
                {
                    pair<int, int> cur = q.back();

                    // 만약 마지막에 들어간 학생의 희망 학생을 본 적 없다면
                    if (vis[cur.second] == 0)
                    {
                        vis[cur.second] = 1;
                        q.push({cur.second, wish[cur.second]});
                    }

                    //  마지막에 들어간 학생의 희망학생이 이미 나왔다면
                    else
                    {
                        // 만약 마지막에 들어간 학생의 희망학생이 아예 다른 그룹이고
                        // 이미 방문됐다면
                        if(check[cur.second] == 1){
                            while(!q.empty()){
                                ans++;
                                check[q.front().first] = 1;
                                q.pop();
                            }

                            continue;
                        }

                        while (q.front().first != cur.second)
                        {
                            check[q.front().first] = 1;
                            ans++;
                            q.pop();
                        }

                        while (!q.empty())
                        {
                            check[q.front().first] = 1;
                            q.pop();
                        }
                    }
                }
            }
        }

    
        cout << ans << '\n';
    }

    return 0;
}

/* O(N^2) 풀이

int arr[100005];
int n;

bool iscycle(int idx){
    int cur = idx;
    for(int i=0; i<n; i++){
        cur = arr[cur];
        if(cur == idx) return true;
    }

    return false;
}

int main(){
    int t;

    cin >> t;

    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(!iscycle(i)) ans++;
        }
        cout << ans << '\n';
    }
}

*/
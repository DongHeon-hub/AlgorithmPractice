#include <bits/stdc++.h>
using namespace std;

int a[20001];
int b[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int t;
    
    cin >> t;

    while (t--)
    {
        int ans = 0;
        cin >> n >> m;

        for (int i = 0; i<n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(a[i] <= b[j])
                    break;

                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
/*

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        vector<pair<int, int>> v(n+m);
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back({a,0});
        }

        for(int i=0; i<m; i++){
            int b;
            cin >> b;
            v.push_back({b,1});
        }

        sort(v.begin(), v.end());

        int cnt=0;
        int ans=0;

        for(int i=0; i<v+m; i++){
            if(v[i].second==0) ans+=cnt;
            else cnt++;
        }

        cout << ans;
    }
}

*/
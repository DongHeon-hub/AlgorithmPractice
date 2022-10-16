#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n;
    int arr[100];

    int v;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> v;

    for (int i = 0; i < n; i++){
        if(arr[i] == v)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}

/*

#include<bits/stdc++.h>

using namespace std;

int a[201]={};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ans=0;
    int t;

    cin >> n;

    while(n--){
        cin >> t;
        a[t+100]++;
    }

    cin >> v;

    cout << a[v+100];

    return 0;
}

//배열의 범위를 음수만큼 증가 시켜 음수도 배열을 통해 접근할 수 있도록 함
*/
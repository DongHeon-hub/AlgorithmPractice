#include<bits/stdc++.h>
using namespace std;
long long arr[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++){
        long v = 1;
        long long temp = arr[i];
        int d = 0; // 몇자리 정수인지 파악

        while(temp){
            temp /= 10;
            d++;
        }

        for (int j = 0; j < d - 1; j++)
            v *= 10;

        temp = arr[i];
        arr[i] = 0;
        while(temp){
            arr[i] += (temp % 10) * v;
            v /= 10;
            temp /= 10;
        }

        
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    
    return 0;
}

/*
int n;
string st;
vector<long long> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> st;
        reverse(st.begin(), st.end());
        v.push_back(stoll(st));
    }

    sort(v.begin(), v.end());

    for(auto i : v) cout << i << '\n';
    return 0;
}
*/
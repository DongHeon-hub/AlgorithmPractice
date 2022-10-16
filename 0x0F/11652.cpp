#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 0;  // 가장 많이 등장한 정수의 index를 저장
    int tmax = 0; // 가장 많이 등장한 정수를 찾기 위한 변수
    int temp = 1;
    

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i-1])
        {
            if (temp > tmax)
            {
                ans = i-1;
                tmax = temp;
            }
            temp = 1;
        }

        else
            temp++;
    }

    if(temp > tmax)
        ans = n-1;

    cout << arr[ans] << '\n';

    return 0;
}

/*
cnt, mxval, mxcnt
cnt : 현재 보고 있는 수가 몇번 등장했는지
mxval : 현재까지 가장 많이 등장한 수의 값
mxcnt : 현재까지 가장 많이 등장한 수의 번수

int cnt=0;
long long mxval = -(111<<62)-1;
int mxcnt=0;

for(int i=0; i<n; i++){
    if(i==0 || a[i-1]==a[i]) cnt++;
    else{
        if(cnt > mxcnt){
            mxcnt = cnt;
            mxval = a[i-1];
        }
        cnt=1;
    }
}

if(cnt > mxcnt) mxval = a[n-1];
cout << mxval;
*/
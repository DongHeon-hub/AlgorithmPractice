#include<bits/stdc++.h>
using namespace std;

int arr[1000001] = {};
int check[1000001] = {};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int num;
    int x;
    int result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[num]++;
    }

    cin >> x;


    for (int i = 0; i < 1000001; i++)
    {
        if (arr[i] == 1)
        {
            if(x-i <=1000000){
                if (2*i != x && arr[x - i] == 1 && check[i] != 1)
                {
                    result++;
                    check[i] = check[x - i] = 1;
                }
            }   
        }
    }

    cout << result << '\n';
    return 0;
}

/*

int a[1000001]={};
bool occur[2000001];
int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> a[i];

    int x;

    cin >> x;

    for(int i=0; i<n; i++){
        if(x-a[i] > 0 && occur[x-a[i]]) ans++; 
        occur[x-a[i]]=1;
    }

    cout << ans;

    return 0;
}   
*/

/*
int a[2000001]={};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, x, ans=0;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> t;
    a[t]++;
  }

  cin >> x;
  for (int i = 1; i < (x+1)/2; ++i) {
    // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
    if (a[i]==1 && a[x-i]==1) ans++;
  }
  cout << ans;
}

*/
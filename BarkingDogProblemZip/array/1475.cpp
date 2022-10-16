#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int num[10] = {};

    int set=1;

    cin >> str;

    
    for (int i = 0; i < str.length(); i++){
        num[str[i] - '0']++;
    }

    if((num[6] + num[9])%2 == 0){
        set = (num[6] + num[9]) / 2;
    }

    else{
        set = (num[6] + num[9]) / 2 + 1;
    }


    for (int i = 0; i < 10; i++){
        if(i!=6 && i!=9){
            if(num[i] > set)
                set=num[i];
        }


    }

    cout << set << '\n';

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // ans = 1로 둠으로서 N = 0일때에 대한 예외처리가 자연스럽게 가능해짐
  int N, a[10] = {}, ans = 1;
  cin >> N;
  
  // 자리수 추출
  while(N){
    a[N%10]++;
    N /= 10;
  }

  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }
  // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
  ans = max(ans, (a[6]+a[9]+1)/2);
  cout << ans;
}



*/
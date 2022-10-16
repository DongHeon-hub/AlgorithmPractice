#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int m;
    int f;
} student;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int n, k;
    int gen, grade;
    student s[7];

    for (int i = 0; i < 7; i++){
        s[i].m = s[i].f = 0;
    }

    cin >> n >> k;

    while(n--){
        cin >> gen >> grade;

        if(gen==0){
            s[grade].f += 1;
        }else{
            s[grade].m += 1;
        }
    }

    for (int i = 1; i < 7; i++){
        if(s[i].m % k == 0)
            ans += s[i].m / k;
        else
            ans += s[i].m / k + 1;

        if(s[i].f % k == 0)
            ans += s[i].f / k;
        else
            ans += s[i].f / k + 1;
    }

    cout << ans << '\n';
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int N, K, ans=0;
int s[2][7]={};  // 성별/반별 학생 수를 저장하는 배열

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  // 학생 수 저장
  for (int i=0; i<N; ++i) {
    int a, b;
    cin >> a >> b;
    s[a][b]++;
  }

  // 필요한 방의 개수 계산
  for (int i=0; i<2; ++i) {
    for (int j=1; j<7; ++j) {
      // 배정에 필요한 만큼 방의 개수 추가
      ans += s[i][j] / K;
      // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
      if (s[i][j] % K) ++ans;
    }
  }
  cout << ans;
}

*/
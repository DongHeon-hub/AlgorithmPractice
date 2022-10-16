#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int num;
    int result[10] = {};
    char ch;

    cin >> a >> b >> c;
    num = a * b * c;
    string s = to_string(num);
    //cout << s << '\n';
    //cout << s.length() << '\n';
    // cout << s << '\n';
    // cout << s.front() << ' ' << s.back() << '\n';
    // return 0;
    for (int i = 0; i < s.length(); i++)
    {
        result[s[i] - '0']++;
    }

    for(int e : result)
        cout << e << '\n';


    return 0;
}

/* int 를 string으로 변환 하려면 in c++

int main(){
    int x=42;
    string s = to_string(x);
    cout << s;
}

정답 코드
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  int t=A*B*C;
  int d[10] = {};
  // 계산 결과를 자릿수별로 확인하여 저장
  while (t>0) {
    d[t%10]++;
    t/=10;
  }
  for (int i=0; i<10; ++i) cout << d[i] << '\n';
}
*/
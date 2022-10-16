#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, a, b;
pair<int,int> p[100004];

bool cmpx(pair<int,int> a, pair<int,int> b){
  return a.X < b.X;
}
bool cmpy(pair<int,int> a, pair<int,int> b) {
  return a.Y < b.Y;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i].X >> p[i].Y;
  }
  
  stable_sort(p, p+n, cmpx);  // x좌표가 증가하는 순
  stable_sort(p, p+n, cmpy); // y좌표가 증가하는 순
  for(int i = 0; i < n; i++) cout << p[i].X << ' ' << p[i].Y << '\n';
  return 0;
}

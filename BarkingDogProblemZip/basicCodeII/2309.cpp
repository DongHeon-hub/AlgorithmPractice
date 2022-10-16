#include<bits/stdc++.h>

using namespace std;

int main(){
    int height[9];
    int n1, n2;
    int sum = 0;
    short flag = 0;

    for (int i = 0; i < 9; i++){
        cin >> height[i];
        sum += height[i];
    }

    sort(height, height + 9);

    // 9명 중 2명을 뺀 조합 조합 중 만약 전체 합에서 둘 뺀게 100이면 나머지 7명이 난쟁이
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum-height[i]-height[j] == 100){
                n1 = i;
                n2 = j;
                flag = 1;
                break;
            }
        }

        if(flag)
            break;
    }

    for (int i = 0; i < 9; i++){
        if(i!=n1 && i!=n2)
            cout << height[i] << '\n';
    }

    return 0;

}


/*
#include <bits/stdc++.h>
using namespace std;

int num[9], result[7];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 0; i < 9; i++) cin >> num[i];
    
  // 9명 중 2명을 뺀 모든 조합 고려
  for(int a = 0; a < 8; a++) {
    int total = 0;
        
    for(int b = a + 1; b < 9; b++) {
      total = 0;
            
      // 나머지 7명 저장
      for(int c = 0, i = 0; c < 9; c++) if(c != a && c != b) result[i++] = num[c];
      for(int i = 0; i < 7; i++) total += result[i];
            
      // 7명 키의 합이 100인 경우
      if(total == 100) break;
    }
    if(total == 100) break;
  }
    
  // 정렬 후 출력
  sort(result, result + 7);
  for(int i = 0; i < 7; i++) cout << result[i] << "\n";
}

*/
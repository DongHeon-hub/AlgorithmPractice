#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y);
void change(int arr[], int left, int right);

int main(){
    int a[21];

    int left, right;
    a[0] = 0;

    for (int i = 1; i <= 20; i++)
        a[i] = i;

    for (int i = 0; i < 10; i++){
        cin >> left >> right;

        if(left > right)
            swap(&left, &right);

        change(a, left, right);
        //break;
    }

    for (int i = 1; i <= 20; i++)
        cout << a[i] << ' ';

        return 0;
}

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void change(int arr[], int left, int right){
    if(left == right)
        return;

    int temp[21] = {0,};

    for (int i = left; i <= right; i++)
        temp[i] = arr[right+left-i];

    for (int i = left; i <= right; i++){
        arr[i] = temp[i];
    }
}

/* 정답 코드

void reverse(int a, int b){
    for(int i=0; i<(b-a+1); i++){
        swap(num[a+i], b[b-i]);
    }
}

*/

/* reverse 함수라는게 있다
algorithm 헤더에 정의 돼있음.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};

    reverse(a, a+5);    // 1 ~ 5 모두 적용
    reverse(b+1, a+4);  // 7 ~ 9 만 적용

    int a_len = sizeof(a)/sizeof(int);   //배열은 원소의 개수를 이렇게 계산해줘야함
    int b_len = sizeof(b)/sizeof(int);

    for (int i=0; i < a_len; i++)
        cout << a[i] << " ";             // 5 4 3 2 1

    cout << endl;

    for (int i=0; i < b_len; i++)
        cout << b[i] << " ";             // 6 9 8 7 10
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vec_a(5);
    vector<int> vec_b(5);

    for (int i = 0; i < 5; i++)
        vec_a[i] = i+1;         // vec_a = 1, 2, 3, 4, 5

    for (int i = 0; i < 5; i++)
        vec_b[i] = i+6;         // vec_b = 6, 7, 8, 9, 10

    reverse(vec_a.begin(), vec_a.end());     // 1 ~ 5 모두 적용
    reverse(vec_b.begin()+1, vec_b.end()-1); // 7 ~ 9 만 적용


    for (int i = 0; i < 5; i++)
        cout << vec_a[i] << " ";     // 5 4 3 2 1

    cout << endl;

    for (int i = 0; i < 5; i++)
        cout << vec_b[i] << " ";    // 6 9 8 7 10
}


reverse를 이용한 풀이는 다음과 같다.
#include <bits/stdc++.h>
using namespace std;

int num[21];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 1; i <= 20; i++) num[i] = i;
    
  for(int i = 1; i <= 10; i++) {
    int a, b;
    cin >> a >> b;        
    reverse(num+a, num+b+1);
  }
    
  for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}


STL reverse를 이용한 풀이
*/
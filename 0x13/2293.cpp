/*
a[i] + a[j] + a[k] = a[l]을 중에서 최댓값
가장 먼저? O(n^4)풀이
4중 for문

O(n^3lgn) : i, j, k에 대한 for문, a[i], a[j], a[k]가 a에 있는지 이분탐색
but 이래도 시간은 부족

-> O(n^2lgn)풀이

1) two배열을 만듬. 배열 a의 원소들 두개의 합을 미리 구해놓은 배열임

two[m] + a[k] = a[l]

-> k,l에 대한 이중 for문. a[l]-a[k] 가 배열 two에 있는지 이분탐색
 O(lgN^2) = O(2lgN)
*/

#include<bits/stdc++.h>
using namespace std;

int a[1005];
int n;
vector<int> two;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n;


    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            two.push_back(a[i] + a[j]);
        }
    }

    sort(two.begin(), two.end());


    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if(binary_search(two.begin(), two.end(), a[i]-a[j])){
                cout << a[i] << '\n';
                return 0;
            }
        }
    }

}

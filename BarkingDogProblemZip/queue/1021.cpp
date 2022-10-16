#include<bits/stdc++.h>

using namespace std;

deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int size;
    int ans = 0;
    cin >> n >> m;
    int *pos = (int *)malloc(sizeof(int) * m);
    size = n;
    for (int i = 0; i < m; i++)
        cin >> pos[i];
    
    for (int i = 0; i < m; i++){
        if(pos[i] <= (size+1)/2){
            ans += (pos[i] - 1); // 연산 필요수

            // 연산이 일어날 때 처음 큐에서의 위치 변화 저장
            for (int j = i + 1; j < m; j++){
                for (int k = 1; k <= (pos[i] - 1); k++){
                    if(pos[j]>1)
                        pos[j]--;
                    else
                        pos[j] = size;
                }
            }
        }

        else{
            ans += (size - pos[i] + 1);

            for (int j = i + 1; j < m; j++){
                for (int k = 1; k <= (size - pos[i] + 1); k++){
                    if (pos[j] < size)
                        pos[j]++;
                    else
                        pos[j] = 1;
                }
            }

        }

        // 맨 처음 원소가 pop 됐으므로 위치가 하나씩 줌
        for (int j = i + 1; j < m; j++)
            pos[j]--;

        size--;
    }

    cout << ans << '\n';
    return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    deque<int> DQ;
    for(int i=1; i<=n; i++) DQ.push_back(i);

    int ans=0;
    while(m--){
        int t;
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin();
        
        while(DQ.front()!=t){
            if(idx < DQ.size()-idx){
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }

            else{
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }

        DQ.pop_front();
    }

    cout << ans;

}

find 함수 : 범위 안에 원하는 값을 찾는 함수입니다.
 
범위 안 (first 부터 last 전 까지) 의 원소들 중 val 과 일치하는 첫 번째 원소를 가리키는 반복자를 리턴합니다. 
만일 일치하는 원소를 찾지 못할 경우 last 를 리턴합니다.
 
이 함수는 원소를 비교할 때 operator== 을 사용합니다.
참고로 이 함수는 string 의 find 함수와 다릅니다.

인자

first, last : 원소들의 시작과 끝을 가리키는 반복자들. 이 때 확인하는 범위는 [first, last) 로 정의됩니다. first 가 가리키는 원소는 포함되지만 last 가 가리키는 원소는 포함되지 않습니다.
val : 비교할 값. 이 때 val 의 타입 T 의 경우 operator== 가 정의되어 있어야만 합니다.

리턴값
첫 번째로 일치하는 원소를 가리키는 반복자. 일치하는 원소가 없을 경우 last 가 리턴됩니다.

*/
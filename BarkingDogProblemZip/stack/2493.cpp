#include<bits/stdc++.h>

using namespace std;

const int mx=500001;
int dat[mx];
int res[mx];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(res, res+mx, -1);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> dat[i];

        if(i==0) continue;

        else{
            if(dat[i-1] > dat[i]){
                res[i] = i-1;
            }

            else{

                int temp=i-1;

                while(temp){
                    if(res[temp] == -1)
                        break;

                    if(dat[res[temp]] > dat[i]){
                        res[i] = res[temp];
                        break;
                    }

                    temp = res[temp];
                }

                if(dat[temp] > dat[i]) res[i] = 0;

            }
        }
    }

    for(int i=0; i<n; i++){
        cout << res[i]+1 << ' ';

    }

    return 0;
}

/* <c++ stl>

https://ya-ya.tistory.com/91 pair 관련 블로그
pair class
: 사용자가 지정한 2개의 타입의 데이터를 저장하는데 사용.
서로 연관된 2개의 데이터를 한 쌍으로 묶어서 사용하면 편리
사용하려면 #include<utility>

해야하지만 vector, algorithm헤더에 이미 포함돼 있어서 vector or algorithm 헤더를 포함하면 됨

p.firstp의 첫번째 인자를 반환합니다.
p.secondp의 두번째 인자를 반환합니다.
make_pair(값1, 값2)값1, 값2를 한쌍으로 하는 pair를 만들어서 반환합니다.

pair<int, double> p;

int main(){
    p.first = 1;
    p.second = 2.1;
    cout << "first value: " << p.first << endl;
    cout << "second value: " << p.second << endl;

    // p = make_pair(1, 2.1); 이렇게 만들어도 됨
    return 0;
}


#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n;
stack<pair<int, int>> tower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    tower.push({100000001, 0});

    for(int i=1; i<=n; i++){
        int height;
        cin >> height;

        while(tower.top().X < height) tower.pop();

        cout << tower.top().Y << " ";
        tower.push({height, i});
    }

}

*/
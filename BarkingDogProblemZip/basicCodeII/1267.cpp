#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int q, r; // 몫, 나머지 저장
    int time; // 통화시간 저장
    int y=0, m=0;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> time;

        if(time%30 == 0){
            if(time==0)
                continue;

            y += (time / 30) * 10+10;
        } else{
            y += (time / 30) * 10 + 10;
        }

        if(time%60 == 0){
            if(time==0)
                continue;
            m += (time / 60) * 15+15;
        } else{
            m += (time / 60) * 15 + 15;
        }
    }

    if(y < m)
        cout << 'Y' << ' ' << y << '\n';
    else if(y==m)
        cout << 'Y' << ' ' << 'M' << ' ' << y << '\n';
    else
        cout << 'M' << ' ' << m << '\n';

    return 0;
}
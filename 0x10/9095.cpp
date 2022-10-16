#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d[12];
    int t;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    cin >> t;

    for (int i = 4; i <= 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    while (t--)
    {
        int n;
        cin >> n;

        cout << d[n] << '\n';
    }

    return 0;
}

/*
다른 문제를 풀다가 비슷한 상황이 있으면 내가 작성한
코드처럼 매 TC마다 테이블을 다시 구하지 말고,
while밖에서 table을 모두 구한뒤 출력만 하는 식으로 하자.
*/
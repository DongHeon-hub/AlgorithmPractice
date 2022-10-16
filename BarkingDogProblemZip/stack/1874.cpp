#include<bits/stdc++.h>

using namespace std;

stack<int> S;
vector<char> v; // 연산들 저장
vector<int> in; // 입력된 배열 저장
vector<int> res; // 최종 결과 입력 배열과 비교

int main(){
    int cur = 1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        in.push_back(x);
    }

    for (cur; cur <= in[0]; cur++){
        S.push(cur);
        v.push_back('+');
    }

    for (int i = 1; i < (int)in.size(); i++){
        if(in[i] < in[i-1])
            continue;

        else{
            int pe;
            while((pe=S.top()) != in[i-1]){
                
                v.push_back('-');
                res.push_back(pe);
                S.pop();
            }

            // pe가 in[i-1]과 같으므로 pop을 한 번 더해줌
            
            v.push_back('-');
            res.push_back(pe);
            S.pop();

            if(cur > in[i]){
                cout << "NO";
                return 0;
            }
            else{
                for (cur; cur <= in[i]; cur++){
                    S.push(cur);
                    v.push_back('+');
                    
                }
            }
        }
    }

    while(!S.empty()){
        v.push_back('-');
        res.push_back(S.top());
        S.pop();
    }

    for (int i = 0; i<(int)in.size(); i++){
        if(in[i]!=res[i]){
            cout << "NO";
            return 0;
        }
    }

        for (char ch : v)
            cout << ch << '\n';
    
    return 0;
}


#include<iostream>
#include<string>

using namespace std;

int func2(int arr[], int n); // 크기가 n이고 각 값이 0~100인 배열에서 서로 합쳐서 100이 되는 두 원소가 존재하면 1, 아니면 0을 리턴

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int a[26];

    fill(a, a + 26, 0);
    cin >> s;

    for (int i = 0; i < s.length(); i++){
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        cout << a[i] << ' ';
    
    return 0;
}


int func2(int arr[], int n){
    int occur[101] = {};
    for (int i = 0; i < n; i++){
        if(occur[100-arr[i]] == 1)
            return 1;
        occur[arr[i]] = 1;
    }

    return 0;
}


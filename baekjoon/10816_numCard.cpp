#include<bits/stdc++.h>
using namespace std;


vector<int> v;
int n, m;

int binarySearch(int key);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cin >> m;
    while(m--){
        int t;
        cin >> t;

        cout << binarySearch(t) << ' ';
        }

    return 0;
}

int binarySearch(int key){
    int ans = 0;
    int left = 0;
    int middle;
    int right = (int)v.size() - 1;

    while(1){
        if(left>right){
            return ans;
        }

        middle = left + (right - left) / 2;

        if(v[middle] == key){
            ans++;
            v.erase(v.begin() + middle);
            left = 0;
            right = (int)v.size() - 1;
        }

        else if(v[middle] < key){
            left = middle + 1;
        }


        else{
            right = middle - 1;
        }
    }
}


#include<bits/stdc++.h>
using namespace std;

int ns[1000002];
int a[1000002];
int res[1000002];
int cnt = 0;

int binarysearch(int target);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        ns[i] = a[i];
    }

    sort(a, a + n);
    

    int temp = a[0];
    res[cnt++] = a[0];

    for (int i = 1; i < n; i++){
        if(temp==a[i])
            continue;
        
        else{
            res[cnt++] = a[i];
            temp = a[i];
        }
    }

    for (int i = 0; i < n; i++){
        cout << binarysearch(ns[i]) << ' ';
    }
}

int binarysearch(int target){
    int st = 0;
    int en = cnt - 1;

    while(st<=en){
        int mid = (st + en) / 2;
        if(target == res[mid])
            return mid;
        
        if(target < res[mid])
            en = mid - 1;
        
        else
            st = mid + 1;
    }
}

/*
barking dog code

int n;
int x[1000005];
vector<int> tmp, uni; // unique
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x[i];
        tmp.push_back(x[i]);
    }

    sort(tmp.begin(), tmp.end());
    for(int i=0; i<n; i++){
        if(i==0 || tmp[i-1]!=tmp[i]) uni.push_back(tmp[i]);
    }

    for(int i=0; i<n; i++){
        cout << lower_bound(uni.begin(), uni,end(), x[i]) - uni.begin() << ' ';
    }
}
*/

/*
stl 이용!

vector<int> uni;

cin >> n;
for(int i=0; i<n; i++){
    cin >> x[i];
    uni.push_back(x[i]);
}

sort(uni.begin(), uni.end());
uni.erase(unique(uni.begin(), uni.end()), uni.end())
*/
#include<bits/stdc++.h>
using namespace std;

pair<int, int> arr[100002];
pair<int, int> temp[100002];

void merge_sort(int st, int en);
void merge(int st, int en);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    merge_sort(0, n);

    for (int i = 0; i < n; i++){
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}

void merge_sort(int st, int en){
    if(en-st==1)
        return;
    int mid = (st + en) / 2;

    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

void merge(int st, int en){
    int mid = (st + en) / 2;

    int lidx = st;
    int ridx = mid;


    for (int i = st; i < en; i++){
        if(lidx == mid)
            temp[i] = arr[ridx++];
        
        else if(ridx == en)
            temp[i] = arr[lidx++];
        
        else if(arr[lidx].first < arr[ridx].first)
            temp[i] = arr[lidx++];
        
        else if(arr[lidx].first == arr[ridx].first && arr[lidx].second <= arr[ridx].second)
            temp[i] = arr[lidx++];
        
        else
            temp[i] = arr[ridx++];
    }

    for (int i = st; i < en; i++)
        arr[i] = temp[i];

}


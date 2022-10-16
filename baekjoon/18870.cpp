#include<bits/stdc++.h>
using namespace std;

pair<int, int> arr[1000002];
int res[1000002];
pair<int, int> temp[1000002];

void merge_sort(int st, int en);
void merge(int st, int en);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    //merge_sort(0, n);
    stable_sort(arr, arr + n);

    int tmp = -1;


    for (int i = 0; i < n; i++){
        if(tmp==arr[i].first){
            res[arr[i].second] = res[arr[i-1].second];
        }

        else{
            if(i!=0 && res[arr[i-1].second]!=i-1){
                res[arr[i].second] = res[arr[i - 1].second] + 1;
                tmp = arr[i].first;
            }
            else{
            res[arr[i].second] = i;
            tmp = arr[i].first;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';

    cout << '\n';

    return 0;
}

void merge_sort(int st, int en){
    if(en-st==1){
        return;
    }

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
        if(lidx == mid){
            temp[i].first = arr[ridx].first;
            temp[i].second = arr[ridx++].second;

        }
        
        else if(ridx == en){
            temp[i].first = arr[lidx].first;
            temp[i].second = arr[lidx++].second;
        }
        
        else if(arr[lidx].first <= arr[ridx].first){
            temp[i].first = arr[lidx].first;
            temp[i].second = arr[lidx++].second;
        }
        
        else{
            temp[i].first = arr[ridx].first;
            temp[i].second = arr[ridx++].second;
            }

    }

    for (int i = st; i < en; i++){
        arr[i] = temp[i];
    }
}
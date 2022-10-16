#include<bits/stdc++.h>
using namespace std;
vector<int> v[200001];
void my_sort(vector<int>& V);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n;

    cin >> n;
    int x, y;

    while(n--){
        cin >> x >> y;
        v[x + 100000].push_back(y);
    }

    for (int i = 0; i < 200001; i++){
        if(v[i].size() != 0){
            my_sort(v[i]);
            for (int j = 0; j < (int)v[i].size(); j++){
                cout << i - 100000 << ' ' << v[i][j] << '\n';
            }
        }
    }

    return 0;
}

void my_sort(vector<int>& V){
    int i, j;
    int temp;

    for (int i = 0; i < (int)V.size() - 1; i++){
        temp = i;

        for (int j = i + 1; j < (int)V.size(); j++){
            if(V[j] < V[temp])
                temp = j;
        }

        if(V[i] != V[temp])
            swap(V[i], V[temp]);
    }
}
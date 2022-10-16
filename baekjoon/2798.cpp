#include<bits/stdc++.h>

using namespace std;

int card[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int max = -1, cmax;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> card[i];

    for (int i = 0; i < n-2; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                cmax = card[i] + card[j] + card[k];
                if(max < cmax && cmax <= m){
                    max = cmax;
                }
            }
        }
    }

    cout << max << '\n';
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[3];

    while(1){
        for(int i=0; i<3; i++)
            cin >> a[i];

        sort(a, a + 3);

        if(a[2] == 0)
            break;
        
        if(a[2]*a[2] == a[0]*a[0] + a[1]*a[1])
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}
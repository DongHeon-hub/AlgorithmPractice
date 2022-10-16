#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[4];
    int count = 0;
    int n = 3;
    


    while(n--){
       cin >> a[0] >> a[1] >> a[2] >> a[3];

        for (int i = 0; i<4; i++){
            if(a[i]==0)
                count++;
        }

        switch (count){
            case 0 :
                cout << 'E' << '\n';
                break;
            case 1 :
                cout << 'A' << '\n';
                break;
            case 2 :
                cout << 'B' << '\n';
                break;

            case 3 :
                cout << 'C' << '\n';
                break;
            case 4 :
                cout << 'D' << '\n';
        }

        count = 0;
    }
    return 0;
}

/* 정답 코드

int result, input;
string res = "DCBAE"

int main(){
     ios::sync_with_stdio_(0);
     cin.tie(0);

     for(int r=0; r<3; r++){
        result=0;
        for(int c=0; c<4; c++){
            cin >> input;
            result+=input;
        }

        cout << res[result] << '\n';
     }
}

*/
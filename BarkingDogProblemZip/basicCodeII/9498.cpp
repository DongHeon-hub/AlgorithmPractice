#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;

    cin >> num;

    if(num >= 90)
        cout << 'A';
    
    else if(num >=80)
        cout << 'B';

    else if(num >= 70)
        cout << 'C';
    
    else if(num >=60)
        cout << 'D';
    
    else
        cout << 'F';

    return 0;
}
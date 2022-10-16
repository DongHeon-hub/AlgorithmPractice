// 거듭 제곱
/*
int func1(int a, int b, int m){
    int val=1;
    while(b--) val*=a;
    return val;
}

만약 6^100과 같이 큰 수면 int overflow가 발생 

using ll = long long;
ll func1(ll a, ll b, ll m){
    ll val=1;
    while(b--){
        val = val*a%m;
    }
    
    return val;
}
*/
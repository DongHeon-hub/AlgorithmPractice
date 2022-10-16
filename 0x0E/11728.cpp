#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000002];
int b[1000002];
int c[2000002];
void Merge(); // 두 정렬된 배열을 합치는 함수
int Compare(int x, int y);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    Merge();

    for (int i = 0; i < n + m; i++)
        cout << c[i] << ' ';
    return 0;
}

void Merge(){
    int sa = 0, sb = 0, sc = 0; // 각 배열의 시작
    

    while(sa!=n && sb!=m){
        switch(Compare(a[sa], b[sb])){
            case -1 :
                c[sc++] = a[sa++];
                break;

            case 0 :
                c[sc++] = a[sa++];
                c[sc++] = b[sb++];
                break;

            case 1 :
                c[sc++] = b[sb++];
                break;
        }
    }

    for (int i = sa; i < n; i++)
        c[sc++] = a[i];

    for (int i = sb; i < m; i++)
        c[sc++] = b[i];

    
    
    return;
}

int Compare(int x, int y){
   if(x>y)
       return 1;
    else if(x<y)
        return -1;
    else
        return 0;
}

/*
void merge(){
    int aidx=0, bidx=0;
    for(int i=0; i<n+m; i++){
        if(bidx==m) c[i] = a[aidx++];
        else if(aidx==n) c[i] = b[bidx++];
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++]; -> stable sort와 관련
        else c[i] = b[bidx++];
    }
}

*/
#include<bits/stdc++.h>

using namespace std;

#define MX 600001
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int cursor=0;

void insert(int addr, int num){
   
        dat[unused] = num;
        nxt[unused] = nxt[addr];
        pre[unused] = addr;
        if(nxt[addr] != -1) pre[nxt[addr]] = unused;
        nxt[addr] = unused;
        unused++;

}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void traversal(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    int m;
    char cmd, ch;
    string s;
    cin >> s;

    for (string::iterator c = s.begin(); c != s.end(); c++){
        insert(cursor, *c);
        cursor++;
    }

    cin >> m;

    while(m--){
        cin >> cmd;

        if(cmd == 'P'){
            cin >> ch;
           
            insert(cursor, ch);
            cursor = nxt[cursor];
        }
        else if(cmd == 'L'){
            if(pre[cursor]!=-1)
                cursor = pre[cursor];
        }

        else if(cmd == 'D'){
            if(nxt[cursor]!=-1)
                cursor = nxt[cursor];
        }

        else{
            if(cursor!=0){
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }

    traversal();
}





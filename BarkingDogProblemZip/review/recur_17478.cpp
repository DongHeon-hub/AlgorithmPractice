#include<bits/stdc++.h>
using namespace std;

int n;

void solve(int k); // �ڸ�Ʈ�� ����ϴ� �Լ�

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    solve(0);

    return 0;
}

void solve(int k){
    for (int i = 0; i < 4*k; i++)
        cout << '_';
    cout << "\"����Լ��� ������?\"\n";
    if(k == n){
        for (int i = 0; i < 4*k; i++)
            cout << '_';

        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for (int i = 0; i < 4*k; i++)
            cout << '_';

        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    
    
    for (int i = 0; i < 4*k; i++)
        cout << '_';
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i = 0; i < 4*k; i++)
        cout << '_';
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i = 0; i < 4*k; i++)
        cout << '_';
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    solve(k + 1);
    
    for (int i = 0; i < 4*k; i++)
        cout << '_';

    cout << "��� �亯�Ͽ���.\n";
}

#include<bits/stdc++.h>
using namespace std;

// n����ŭ ���ϴ� �ڸ�Ʈ�� ������ִ� �Լ�
void func(int n, int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k = 0;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
        func(n, k);
    return 0;
}

void func(int n, int k){

    if(n==0){
        for (int i = 0; i < 4 * k; i++)
        cout << '_';
        cout << "\"����Լ��� ������?\"\n";
        for (int i = 0; i < 4 * k; i++)
        cout << '_';
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for (int i = 0; i < 4 * k; i++)
        cout << '_';
        cout << "��� �亯�Ͽ���.\n";
        return;
    }

    for (int i = 0; i < 4 * k; i++)
        cout << '_';
    cout << "\"����Լ��� ������?\"\n";
    for (int i = 0; i < 4 * k; i++)
        cout << '_';
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i = 0; i < 4 * k; i++)
        cout << '_';
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i = 0; i < 4 * k; i++)
        cout << '_';
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    func(n - 1, k+1);
    for (int i = 0; i < 4 * k; i++)
        cout << '_';
    cout << "��� �亯�Ͽ���.\n";
}
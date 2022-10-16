#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    int a;
    int b;
    int c;
} student;

bool cmp(const student&x, const student&y){
    if(x.a != y.a)
        return x.a > y.a;

    else{
        if(x.b != y.b)
            return x.b < y.b;
        
        else{
            if(x.c != y.c)
                return x.c > y.c;
            
            else{
                return x.name < y.name;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<student> v;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        student temp;

        cin >> temp.name >> temp.a >> temp.b >> temp.c;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);


    for(auto &e : v)
        cout << e.name << '\n';

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<tuple<int, int, string>> members;
  for (int i = 0; i < N; i++) {
    int age;
    string name;
    cin >> age >> name;
    members.push_back({age, i, name});
  }
  sort(members.begin(), members.end());
  for (auto [age, _, name] : members)
    cout << age << " " << name << '\n';
}

*/
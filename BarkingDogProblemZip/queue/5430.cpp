#include <bits/stdc++.h>

using namespace std;

deque<int> DQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool flag = false;
    int rev = -1; // R안하면 -1
    int t;
    string str;
    string temp = "", input;

    int n;
    
    cin >> t;

    while (t--)
    {
        cin >> str;
        cin >> n;
        cin >> input;

        if (n != 0)
        {
            for (int i = 0; i < input.length(); i++)
            {
                if (input[i] == '[' || input[i] == ',' || input[i] == ']')
                {
                    if (input[i] != '[')
                    {
                        if (temp != "")
                        {
                            DQ.push_back(stoi(temp));
                            temp = "";
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }

                temp += input[i];
            }
        }

        for (string::iterator it = str.begin(); it != str.end(); it++)
        {
            if (*it == 'R')
                rev *= -1;

            else
            {
                if (DQ.empty())
                {
                    cout << "error\n";
                    flag = true;
                    break;
                }

                if(rev == 1){
                    DQ.pop_back();
                }
                else
                    DQ.pop_front();
            }
        }


        if (!flag)
        {
            cout << '[';
            if (!DQ.empty())
            {
                //거꾸로 출력
                if(rev == 1){
                    for (deque<int>::iterator it = DQ.end() - 1; it != DQ.begin(); it--)
                        cout << *it << ',';

                    cout << *(DQ.begin());
                }

                else{
                    for (deque<int>::iterator it = DQ.begin(); it != DQ.end() - 1; it++)
                        cout << *it << ',';

                    cout << *(DQ.end() - 1);
                }
            }

            cout << ']';
            cout << '\n';
        }

        flag = false;
        rev = -1;
        DQ.clear();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char str[100000];

    

    while (1)
    {

        bool flag = false;
        cin >> str;
        

        if(strlen(str) == 1 && str[0] == '0')
            break;

        if (strlen(str) % 2 == 0)
        {
            int pos = strlen(str) / 2;

            for (int i = 0; i < strlen(str) / 2; i++)
            {
                if (str[pos - 1 - i] != str[pos + i])
                {
                    cout << "no\n";
                    flag = true;
                    break;
                }
            }
        }

        else
        {
            int pos = strlen(str) / 2;

            for (int i = 0; i < strlen(str) / 2; i++)
            {
                if (str[pos - 1 - i] != str[pos + 1 + i])
                {
                    cout << "no\n";
                    flag = true;
                    break;
                }
            }
        }

        if(!flag)
            cout << "yes\n";
    }
    return 0;
}

/*

#include<bits/stdc++.h>

using namespace std;

int main(){
    char s[6];

    while(1){
        scanf("%s", s);
        if(s[0] == 48) break;

        int len = strlen(s)-1;
        int e=0;

        for(int i=0; i<len; i++){
            e += (s[i] != s[n-i])
        }

        printf("%s\n", e ? "no" : "yes");
    }
}
*/
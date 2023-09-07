#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;

    cin >> N;

    int num = 0;

    for(int j = 0; j < N; j++)
    {
        string s;

        cin >> s;

            if(s == "add")
            {
                int i;

                cin >> i;

                num |= (1 << i);
            }
            if(s == "check")
            {
                int i;

                cin >> i;

                cout << ((num & (1<<i)) > 0) << "\n";
            }
            if(s == "remove")
            {
                int i;

                cin >> i;

                num &= ~(1 << i);
            }
            if(s == "toggle")
            {
                int i;

                cin >> i;

                num ^= (1 << i);
            }
            if(s == "all")
            {
                num = 0x1fffff;
            }
            if(s == "empty")
            {
                num = 0;
            }
    }
}
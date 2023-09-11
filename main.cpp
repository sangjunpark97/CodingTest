#include <bits/stdc++.h>

using namespace std;

int mp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    string s;

    cin >> s;
    
    string n;

    cin >> n;

    string f;

    int i = 0;
    int cnt = 0;

    string tmp;

    while(i != s.length())
    {
        if(cnt < n.size() && s[i] == n[cnt])
        {
            tmp.push_back(n[cnt]);
            cnt++;
        }
        else if(cnt == n.size())
        {
            tmp.clear();
            cnt = 0;

            if(s[i] == n[cnt])
            {
                tmp.push_back(n[cnt]);
                cnt++;
            }
            else
            {
                f.push_back(s[i]);
            }
        }
        else
        {
            f+=tmp;
            tmp.clear();
            cnt = 0;

            if(s[i] == n[cnt])
            {
                tmp.push_back(n[cnt]);
                cnt++;
            }
            else
            {
                f.push_back(s[i]);
            }
        }

        i++;
    }

    long long pos;

    while((pos = f.find(n)) != string::npos)
    {
        f.erase(f.begin() + pos, f.begin() + pos + n.length());
    }

    if(f.length())
        cout << f;
    else
        cout << "FRULA";
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;

    cin >> s;
    cin >> t;

    string ret;

    for(auto c : s)
    {
        ret += c;

        if(ret.length() >= t.length() && ret.substr(ret.size() - t.size(), ret.size()) == t)
            ret.erase(ret.end() - t.size(), ret.end());
    }

    if(ret.size())
        cout << ret;
    else
        cout << "FRULA";
}
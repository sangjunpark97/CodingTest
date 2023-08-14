#include <bits/stdc++.h>

using namespace std;

vector<string> split(string strInput, string strDelimiter)
{
    vector<string> strReturn;
    long long int i64Pos = 0;

    while((i64Pos = strInput.find(strDelimiter)) != string::npos)
    {
        strReturn.push_back(strInput.substr(0, i64Pos));
        strInput.erase(0, i64Pos + strDelimiter.length());
    }

    strReturn.push_back(strInput);

    return strReturn;
}

int main()
{
    string strInput = "안녕하세요 감사합니다 행복하세요";
    string strDelimiter = " ";
    vector<string> strOut;

    strOut = split(strInput, strDelimiter);

    for(auto i : strOut)
    {
        cout << i << "\n";
    }

    return 0;
}
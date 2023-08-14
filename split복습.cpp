#include <bits/stdc++.h>

using namespace std;

vector<string> split(string strInput, string strDelimiter)
{
    long long int i64Pos = 0;
    vector<string> vctStrReturn;

    while((i64Pos = strInput.find(strDelimiter)) != string::npos)
    {
        vctStrReturn.push_back(strInput.substr(0, i64Pos));
        strInput.erase(0, i64Pos + strDelimiter.length());
    }

    vctStrReturn.push_back(strInput);

    return vctStrReturn;
}

int main()
{
    string strInput = "안녕하세요 감사합니다 행복하세요";
    string strDelimiter = "요";
    vector<string> strOut;

    strOut = split(strInput, strDelimiter);

    for(auto i : strOut)
    {
        cout << i << "\n";
    }

    return 0;
}
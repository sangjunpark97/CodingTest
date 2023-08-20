#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string strP, strTmp;

    cin >> n;
    cin >> strTmp;

    for(int i = 0; i < n; ++i)
    {
        string strI;
      
        cin >> strI;

        int k = 0;
        
        strP = strTmp;
        
        if(strI.length() < strP.length() - 1)
        {
            cout << "NE" << "\n";
            continue;
        }
      
        while(strP[k] != '*' && strI[k] != '\0')
        {
            if(strP[k] != strI[k])
                break;

            k++;
        }

        if(strP[k] == '*')
        {
            auto pos = strP.find('*');

            strP.erase(0, pos + 1);

            k = 0;
            int t = strI.length() - strP.length();
            
            while(strP[k] == strI[t] && strP[k] != '\0' && strI[t] != '\0')
            {
               k++;
               t++;
            }

            if(strI[t] == '\0' && strP[k] == '\0')
               cout << "DA" << "\n";
            else
               cout << "NE" << "\n";
        }
        else
            cout << "NE" << "\n";
    }
}
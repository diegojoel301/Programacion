#include<bits/stdc++.h>
 
using namespace std;
 
int lcs(string s1, string s2, int len1, int len2)
{
    int i = 0, j = 0;
    int lcs[len1 + 1][len2 + 1];
    
    ciclo_1:
    {
        j = 0;
        ciclo_2:
        {
            if(i != 0 and j != 0) goto condicion_1;
            {   
                lcs[i][j] = 0;
                goto condicion_3;
            }
            condicion_1:
            {
                if(s1[i - 1] != s2[j - 1]) goto condicion_2;
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    goto condicion_3;
                }
                condicion_2:
                {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                    goto condicion_3;
                }
            }
            condicion_3: j++;
        }
        if(j <= len2) goto ciclo_2;
        i++;
    }
    if(i <= len1) goto ciclo_1;
    /*
    for(i = 0; i <= len1; i++)
    {
        for(j = 0; j <= len2; j++)
        {
            if(i == 0 or j == 0)
                lcs[i][j] = 0;
            else if(s1[i - 1] == s2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    */

    return lcs[len1][len2];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string X, Y;

    /*
    while(getline(cin, X))
    {
        getline(cin, Y);
        cout << lcs(X, Y, X.size(), Y.size()) << "\n";    
    }
    */

    bool comodin = false;

    ciclo:

        if(not comodin) goto condicion;
        {
            getline(cin, Y);
            cout << lcs(X, Y, X.size(), Y.size()) << "\n";    
        }

        condicion: comodin = true;
    if(getline(cin, X)) goto ciclo;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void f(string set, string prefix, int n, int k)
{
    if (k == 0)
    {
        cout << (prefix) << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string newPrefix;
         
        newPrefix = prefix + set[i];
         
        f(set, newPrefix, n, k - 1);
    }
 
}
 
int main()
{
    string entrada, set = "";
    getline(cin, entrada);

    map<int, string> mapa;
    mapa[2] = "abc";
    mapa[3] = "def";
    mapa[4] = "ghi";
    mapa[5] = "jkl";
    mapa[6] = "mno";
    mapa[7] = "pqrs";
    mapa[8] = "tuv";
    mapa[9] = "wxyz";

    for(int i = 0; i < entrada.length(); i++)
    {
        set += mapa[int(entrada[i]) - 48];
    }

    cout << set << "\n";
    int k = entrada.length(), n = set.length();

    f(set, "", n, k);
}
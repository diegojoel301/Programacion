#include <bits/stdc++.h>
using namespace std;
 
void f(int izq, int der, string& str, vector<string>& res)
{
    if (der == 0 && izq == 0) {
        res.push_back(str);
    }
 
    if (izq > der || izq < 0 || der < 0) {
        return;
    }
 
    str.push_back('(');
    f(izq - 1, der, str, res);
    str.pop_back();
 
    str.push_back(')');
    f(izq, der - 1, str, res);
    str.pop_back();
}
 
int main()
{
    int t;

    map<int, string> mapa;

    for(int i = 1; i <= 10; i++)
    {
        vector<string> ans;
        string s, out;

        f(i, i, s, ans);

        for (auto k : ans) {
            out += k + "\n";
        }
        mapa[i] = out;
    }

    while(cin >> t)
        cout << mapa[t];


    return 0;
}
#include<bits/stdc++.h>
 
using namespace std;
 
bool sortbysec(const pair<string, int> &a, const pair<string , int> &b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
 
void mostrar(vector<pair<string , int>> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";
}
 
int main()
{
    map<string, int> mapa;
    vector<pair<string , int>> v;
    string state, nameA, nameB;
     
    while(cin >> state >> nameA)
    {
        if(state == "E")
        {
            cin >> nameB;
            mapa[nameA] += 1;
            mapa[nameB] += 1;
        }
        else
            mapa[nameA] += 2;
    }
 
    map<string, int>::iterator itr;
    for(itr = mapa.begin(); itr != mapa.end(); itr++)
        v.push_back(make_pair(itr->first, itr->second));
 
    sort(v.begin(), v.end(), sortbysec);
 
    mostrar(v);
 
    return 0;
}
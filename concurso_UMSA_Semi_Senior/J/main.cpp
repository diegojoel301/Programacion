#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, value;
 
    while(cin >> n)
    {
        vector<int> v;
 
        while(n--)
        {
            cin >> value;
            v.push_back(value);
        }
 
        sort(v.begin(), v.end());
 
        cout << v[v.size() - 1] - v[0] << "\n";
 
    }
 
 
    return 0;
}
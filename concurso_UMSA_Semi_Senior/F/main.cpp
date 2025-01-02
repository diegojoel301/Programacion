#include<bits/stdc++.h>
  
using namespace std;
  
int main()
{
    int N, L, c;
  
    cin >> N;
  
    while(N--)
    {
        cin >> L;
        c = 0;
  
        vector<int> v(L);
  
        for(int i = 0; i < L; i++) cin >> v[i];
  
        for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < L - 1; j++)
            {
                if(v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    c++;
                }
            }
        }
  
        cout << c << "\n";
    }
    return 0;
}

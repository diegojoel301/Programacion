#include<bits/stdc++.h>
#define M 1001
using namespace std;

vector<bool> sieve(M, true);

void gen()
{
        for(int p = 2; p * p < M; p++)
        {
                if(sieve[p])
                {
                        for(int i = p * 2; i < M; i += p)
                                sieve[i] = false;
                }
        }
        sieve[0] = false;
}

int vecino(int x)
{
        int pos = x + 1;
        while(not sieve[pos])
                pos++;

        return pos;
}

bool verifica(int n)
{
        for(int p1 = 2; p1 <= n - 1; p1++)
        {
                if(sieve[p1])
                {
                        int p2 = vecino(p1);

                        if(p1 + p2 == n - 1)
                        return true;
                }
        }
    return false;
}

int main()
{
        gen();

        int n, k, c = 0;

        cin >> n >> k;

        for(int i = 2; i <= n; i++)
        {
                if(sieve[i])
                {
                        if(verifica(i))
                                c++;
                }
        }

        if(c >= k)
                cout << "YES\n";
        else
                cout << "NO\n";

        return 0;
}

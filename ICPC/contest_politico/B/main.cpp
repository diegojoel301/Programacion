#include<bits/stdc++.h>

using namespace std;

const int M = 1000000;

bool prime[M + 1];

void criba()
{
        memset(prime, true, sizeof(prime));

        for(int p = 2; p * p <= M; p++)
        {
                if(prime[p] == true)
                {
                        for(int i = p * 2; i <= M; i += p)
                                prime[i] = false;
                }
        }
        prime[0] = prime[1] = false;
}

int proximo(int n)
{
        while(not prime[n])
                n++;
        return n;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        freopen("input.txt", "r", stdin);

        criba();

        int t, ans;

        cin >> t;

        while(t--)
        {
                vector<int> v(5);

                for(int i = 0; i < 5; i++)
                        cin >> v[i];

                ans = 0;

                for(int i = 0; i < v.size(); i++)
                        ans += proximo(v[i]);

                cout << ans << "\n";
        }

        return 0;
}

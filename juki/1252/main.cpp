#include<bits/stdc++.h>
#define M 200000

using namespace std;

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

int GetCombinationsBitwise(vector<int> & vec, int x)
{
	int sz = vec.size(), cnt = 0;

	for(int mask = 0; mask < (1 << sz); mask++)
	{
		int cnt_primes = 0, len = 0;

		for(int pos = 0; pos < sz; pos++)
		{
			if(mask & (1 << pos))
			{
				if(prime[vec[pos]])
					cnt_primes++;

				len++;
			}
		}
		if(prime[len] and cnt_primes >= x)
			cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	criba();
	int n, x;

	cin >> n >> x;

	vector<int> vec(n);

	for(int i = 0; i < n; i++) cin >> vec[i];

	cout << GetCombinationsBitwise(vec, x) << "\n";
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool esPrimo(int n)
{
	if(n == 1)
		return false;

	for(int x = 2; x * x <= n; x++)
	{
		if(n % x == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;

	cin >> n;
	vector<int> v(n), nv;

	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for(int i = 0, prime; i < n; i++)
	{
		if(esPrimo(v[i]) and v[i] != -1)
		{
			prime = v[i];
			nv.push_back(prime);

			v[i] = -1;
			
			for(int k = nv.size() - 2; k >= 0; k--)
			{
				if(nv[k] % prime == 0 and nv[k] != -1)
				{
					nv.push_back(nv[k]);
					nv[k] = -1;
				}
			}

			for(int j = i + 1; j < n; j++)
			{
				if(v[j] % prime == 0 and v[j] != -1)
				{
					nv.push_back(v[j]);
					v[j] = -1;
				}
			}
		}
	}


	for(int i = 0, prime; i < n; i++)
	{
		if(v[i] != -1)
		{
			prime = v[i];
			nv.push_back(prime);

			v[i] = -1;
			
			for(int k = i - 1; k >= 0; k--)
			{
				if(v[k] % prime == 0 and v[k] != -1)
				{
					nv.push_back(v[k]);
					v[k] = -1;
				}
			}

			for(int j = i + 1; j < n; j++)
			{
				if(v[j] % prime == 0 and v[j] != -1)
				{
					nv.push_back(v[j]);
					v[j] = -1;
				}
			}
		}
	}


	for(int i = 0; i < nv.size() - 1; i++)
	{
		if(nv[i] != -1)
			cout << nv[i] << " ";
	}

	cout << nv[nv.size() - 1] << "\n";

	return 0;
}
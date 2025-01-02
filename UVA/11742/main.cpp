#include<bits/stdc++.h>

using namespace std;

int f(int n)
{
	if(n == 0)
		return 1;
	else
		return n * f(n - 1);
}

int main()
{
	int n, m, cs, a, b, c;

	while(true)
	{
		cin >> n >> m;
		if(n == 0 and m == 0)
			break;

		if(m == 0)
		{
			cout << f(n) << "\n";
			continue;
		}

		vector<tuple<int, int, int, bool>> condiciones;

		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			condiciones.push_back(make_tuple(a, b, abs(c), c >= 0));
		}

		cs = 0;
		vector<int> A;
		
		for(int i = 0; i < n; i++)
			A.push_back(i);

		bool flag, cumple;
		do
		{
			cumple = true;
			for(int k = 0, aa, bb, cc; k < m; k++)
			{
				aa = get<0>(condiciones[k]);
				bb = get<1>(condiciones[k]);
				cc = get<2>(condiciones[k]);
				flag = get<3>(condiciones[k]);


				int posa, posb, distance;
				for(int j = 0; j < A.size(); j++)
				{
					if(A[j] == aa)
						posa = j;
					if(A[j] == bb)
						posb = j;
				}
				distance = abs(posa - posb);
				
				if(flag)
				{
					if(distance > cc)
					{
						cumple = false;
						break;
					}
				}
				else
				{
					if(distance < cc)
					{
						cumple = false;
						break;
					}
				}	
				
			}
			if(cumple)
				cs++;
			
		}while(next_permutation(A.begin(), A.end()));
			
		cout << cs << "\n";
	
	}

	

	return 0;
}
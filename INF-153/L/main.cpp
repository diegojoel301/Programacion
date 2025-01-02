#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	vector<int> a(n), b(n);

	int i = 0;

	ciclo_1:
	{
		cin >> a[i];
		i++;
	}
	if(i < n) goto ciclo_1;

	i = 0;

	ciclo_2:
	{
		cin >> b[i];
		i++;
	}
	if(i < n) goto ciclo_2;

	i = 0;

	char sgn;

	ciclo_3:
	{
		cin >> sgn;

		if(sgn != '+') goto condicion_1;
		{
			cout << a[i] + b[i] << "\n";
			goto condicion;
		}
		condicion_1:
		{
			if(sgn != '*') goto condicion_2;
			{
				cout << a[i] * b[i] << "\n";
				goto condicion;
			}

			condicion_2:
			{
				if(sgn != '<') goto condicion_3;
				{
					if(a[i] >= b[i]) goto condicion_4;
					{
						cout << a[i] << "\n";
						goto condicion;
					}
					condicion_4: cout << b[i] << "\n";
					goto condicion;
				}
				condicion_3:
				{
					if(sgn != '>') goto condicion;
					{
						if(a[i] <= b[i]) goto condicion_6;
						{
							cout << a[i] << "\n";
							goto condicion;
						}
						condicion_6: cout << b[i] << "\n";
						goto condicion;
					}
				}
			}
		}

		condicion: i++;
	}
	if(i < n) goto ciclo_3;	

	return 0;
}
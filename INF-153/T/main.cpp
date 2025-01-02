#include<bits/stdc++.h>
#define N 1e3 + 50

using namespace std;

bool ok(char x)
{
	return (x >= '2' and x <= '9') or x == 'A' or x == 'J' or x == 'K' or x == 'Q';
}

bool check(string &a)
{
	int i = 0;

	ciclo_1:

		if(ok(a[i])) goto condicion_1;
			return false;

		condicion_1: i++;

	if(i < (int)a.size()) goto ciclo_1;
	/*
	for(int i = 0; i < (int) a.size(); i++)
	{
		if(not ok(a[i]))
			return false;
	}*/
	return true;
}

int n, m;

string a, b;

int dp[1010][1010];

int f(int i, int j)
{
	if(i != n and j != m) goto condicion_6;
		return 0;

	condicion_6:
	{
		int &ans = dp[i][j];

		if(ans == -1) goto condicion_7;
			return ans;

		condicion_7:
		{
			ans = 0;

			if(a[i] != b[j]) goto condicion_8;
				ans = max(ans, f(i + 1, j + 1) + 1);
			condicion_8:
			{
				ans = max(ans, f(i + 1, j));
				ans = max(ans, f(i, j + 1));

				return ans;
			}

		}
	}
	/*
	if(i == n or j == m)
		return 0;

	int &ans = dp[i][j];

	if(ans != -1)
		return ans;

	ans = 0;

	if(a[i] == b[j])
		ans = max(ans, f(i + 1, j + 1) + 1);

	ans = max(ans, f(i + 1, j));
	ans = max(ans, f(i, j + 1));

	return ans;
	*/
}

void build(int i, int j)
{
	if(i != n and j != m) goto condicion_2;
		return;

	condicion_2:
	{
		int ans = dp[i][j];

		if(a[i] != b[j] or ans != f(i + 1, j + 1) + 1) goto condicion_3;
		{
			cout << a[i];
			build(i + 1, j + 1);
			return;
		}
		condicion_3:
		{
			if(ans != f(i + 1, j)) goto condicion_4;
			{
				build(i + 1, j);
				return;
			}
			condicion_4:
			{
				if(ans != f(i, j + 1)) goto condicion_5;
				{
					build(i, j + 1);
					return;
				}
				condicion_5: return;
			}
		}
	}
	
	/*
	if(i == n or j == m)
		return;

	int ans = dp[i][j];

	if(a[i] == b[j] and ans == f(i + 1, j + 1) + 1)
	{
		cout << a[i];
		build(i + 1, j + 1);
		return;
	}

	if(ans == f(i + 1, j))
	{
		build(i + 1, j);
		return;
	}

	if(ans == f(i, j + 1))
	{
		build(i, j + 1);
		return;
	}
	*/
}

void programa()
{
	n = (int) a.size();
	m = (int) b.size();

	if(n == m) goto condicion_10;
	{
		cout << "Deben tener la misma CANTIDAD DE CARTAS!!\n";
		return;
	}
	condicion_10:
	{
		if(not check(a) or not check(b)) goto condicion_11;
		{
			int i = 0, j = 0;

			ciclo_4:
				j = 0;
				ciclo_3:
					dp[i][j] = -1;
					j++;
				if(j <= m) goto ciclo_3;
				i++;
			if(i <= n) goto ciclo_4;
			int ans = f(0, 0);
			cout << "La longitud de la Subsecuencia es: " << ans << "\n";
			build(0, 0);
			cout << "\n";
			return;
		}
		condicion_11:
		{
			cout << "LAS CARTAS NO PERTENECEN A LA BARAJA!!\n";
			return;	
		}
	}
	/*
	if(n != m)
		cout << "Deben tener la misma CANTIDAD DE CARTAS!!\n";
	else if(check(a) and check(b))
	{
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				dp[i][j] = -1;

		int ans = f(0, 0);
		cout << "La longitud de la Subsecuencia es: " << ans << "\n";
		build(0, 0);
		cout << "\n";
	}
	else
		cout << "LAS CARTAS NO PERTENECEN A LA BARAJA!!\n";
	*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool comodin = false;
	/*
	while(cin >> a >> b)
	{
		programa();	
	}
	*/
	ciclo_2:

		if(not comodin) goto condicion_9;
			programa();
		condicion_9: comodin = true;

	if(cin >> a >> b) goto ciclo_2;

	return 0;
}
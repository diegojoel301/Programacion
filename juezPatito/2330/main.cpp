#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x = 0, c = 0, sc = 0, mat[100][100], n, m, cn = 0, cm = 0, val1 = 1, a = -1, b = 1, val = 0;
	bool state = false;

	cin >> n >> m;

	memset(mat, 0, sizeof mat);

	while(x++ != n * m)
	{
		//cout << val << " ";
		if(not state)
		{
			if(x > 1)
			{
				val = a + b;
				a = b;
				b = val;
				mat[cn][cm] = val;
			}

		}
		else
		{
			mat[cn][cm] = val1;
			val1 *= 2;
		}

		cm++;

		if(cm == m)
		{
			state = (cn + 1) % 2 != 0;
			cm = 0;
			cn++;

		}		
	}
	
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < m - 1; j++)
			cout << mat[i][j] << " ";
		cout << mat[i][m - 1] << "\n";
	}
	for(int i = 0; i < n - 1; i++)
	{
		cout << mat[n - 1][i] << " ";
	}
	cout << mat[n - 1][m - 1];
	
	return 0;
}
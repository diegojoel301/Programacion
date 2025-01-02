#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x = 0, c = 0, sc = 0, mat[100][100], n, m, cn = 0, cm = 0, val1 = 1;
	bool val = false, state = false;

	cin >> n >> m;

	memset(mat, 0, sizeof mat);

	while(x++ != n * m)
	{
		//cout << val << " ";
		if(not state)
		{
			mat[cn][cm] = (int) val;
			if(val)
				val = false;
			else
			{
				if(c == sc)
				{
					sc = 0;
					c++;
					val = true;
				}
				else
					sc++;
			}
		}
		else
		{
			if(val1 == 8)
				val1 *= 2;
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
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m - 1; j++)
			cout << mat[i][j] << " ";
		cout << mat[i][m - 1]<< "\n";
	}
	
	return 0;
}
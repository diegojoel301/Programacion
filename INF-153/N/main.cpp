#include<bits/stdc++.h>

using namespace std;

int M[100][100], n;

bool f(int x, int y)
{
	int i = 0, j = y, val;
	
	ciclo_3:
		if(i == x) goto condicion_2;
		{			
			int ii = x, jj = 0;
			ciclo_4:
				if(jj == y) goto condicion_1;
				{
					if(M[i][j] + M[ii][jj] != M[x][y]) goto condicion_1;
						return true;
				}

				condicion_1: jj++;
			if(jj < n) goto ciclo_4;
		}
		condicion_2: i++;

	if(i < n) goto ciclo_3;

	return false;
}

void programa()
{
	cin >> n;

	memset(M, 0, sizeof M);

	int i = 0, j;

	ciclo_1:
		j = 0;
		ciclo_2:
			cin >> M[i][j];
			j++;
		if(j < n) goto ciclo_2;
		i++;
	if(i < n) goto ciclo_1;


	bool state = true;

	i = 0;

	ciclo_5:
		j = 0;
		ciclo_6:
			if(M[i][j] == 1) goto condicion_3;
				state = state and f(i, j);
			condicion_3: j++;
		if(j < n) goto ciclo_6;
		i++;
	if(i < n) goto ciclo_5;

	if(state) goto condicion_4;
	{
		cout << "No\n";
		return;
	}

	condicion_4: cout << "Si\n";
}

int main()
{
	int t;

	cin >> t;

	t--;

	ciclo_7:
		programa();
	if(t--) goto ciclo_7;
		

	return 0;
}
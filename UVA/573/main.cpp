#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	double h, d, u, f;

	while(true)
	{
		cin >> h >> u >> d >> f;
		if(h == 0)
			break;

		double res = (f * u) / 100;

		double mat[10000][5];

		memset(mat, 0, sizeof mat);

		int dia = 0;
		
		mat[dia][0] = dia;
		mat[dia][1] = 0.0;
		mat[dia][2] = u;
		mat[dia][3] = mat[dia][1] + mat[dia][2];
		mat[dia][4] = mat[dia][3] - d;
		/*
		if(mat[dia][3] >= h)
		{
			cout << "success on day 1\n";
			continue;		
		}
		*/
		while(true)
		{
			if(dia > 0)
			{
				mat[dia][0] = dia;
				mat[dia][1] = mat[dia - 1][4];

				if(mat[dia - 1][2] - res <= 0)
					mat[dia][2] = 0;
				else
					mat[dia][2] = mat[dia - 1][2] - res;
				mat[dia][3] = mat[dia][1] + mat[dia][2];
				mat[dia][4] = mat[dia][3] - d;

				if(mat[dia][3] > h)
				{
					cout << "success on day " << dia + 1 << "\n";
					break;	
				}

				if(mat[dia][4] < 0)
				{
					cout << "failure on day " << dia + 1 << "\n";
					break;
				}
			}
			else
			{
				
				if(mat[dia][3] > h)
				{
					cout << "success on day 1\n";
					break;	
				}
				
				if(mat[dia][4] < 0)
				{
					cout << "failure on day 1\n";
					break;	
				}
				
				
			}
			dia++;
		}
	}
	return 0;
}
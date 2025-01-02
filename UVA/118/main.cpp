#include<bits/stdc++.h>

using namespace std;

const int M = 1000;

bool mat[M][M];

void convert(int &xx, int &yy, char dir)
{
	if(dir == 'E')
	{
		xx = 1;
		yy = 0;
	}
	if(dir == 'W')
	{
		xx = -1;
		yy = 0;
	}
	if(dir == 'N')
	{
		xx = 0;
		yy = 1;
	}
	if(dir == 'S')
	{
		xx = 0;
		yy = -1;
	}
}

void convert1(char op, char &dir)
{
	if(op == 'R' and dir == 'E')
		dir = 'S';
	else if(op == 'L' and dir == 'E')
		dir = 'N';
	else if(op == 'R' and dir == 'W')
		dir = 'N';
	else if(op == 'L' and dir == 'W')
		dir = 'S';
	else if(op == 'R' and dir == 'N')
		dir = 'E';
	else if(op == 'L' and dir == 'N')
		dir = 'W';
	else if(op == 'R' and dir == 'S')
		dir = 'W';
	else if(op == 'L' and dir == 'S')
		dir = 'E';

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
			mat[i][j] = false;
	}

	int n, m, x, y, xx, yy, xp, yp;

	char dir;

	string op;
	//columnas, filas
	cin >> m >> n;

	while(cin >> x >> y >> dir)
	{
		convert(xx, yy, dir);

		cin.ignore();
		getline(cin, op, '\n');

		xp = (M / 2) + x;
		yp = (M / 2) + y;

		bool lost = false;

		mat[yp][xp] = 1;

		for(int i = 0; i < op.size(); i++)
		{
			//cout << xp - 500 << " " << yp - 500 << " " << dir << "\n";
			if(op[i] == 'F')
			{
				/*
				convert(xx, yy, dir);
				mat[yp][xp] = 0;
				xp += xx;
				yp += yy;
				mat[yp][xp] = 1;*/
				int auxxp = xp, auxyp = yp;
				convert(xx, yy, dir);

				if((xp + xx) - 500 >= m + 1 or (xp + xx) - 500 < 0 or (yp + yy) - 500 >= n + 1 or (yp + yy) - 500 < 0)
				{
					//cout << "\t" << xp + xx - 500 << " " << yp + yy - 500 << "<----->" << auxxp - 500 << " " << auxyp - 500 << "\n";
					if(not mat[yp + yy][xp + xx])
					{
						lost = true;
						mat[yp + yy][xp + xx] = 1;

						if((auxxp + 1) - 500 >= m + 1 or (auxxp + 1) - 500 < 0 or auxyp - 500 >= n + 1 or auxyp - 500 < 0)
							mat[auxyp][auxxp + 1] = 1;
						if(auxxp - 500 >= m + 1 or auxxp - 500 < 0 or (auxyp + 1) - 500 >= n + 1 or (auxyp + 1) - 500 < 0)
							mat[auxyp + 1][auxxp] = 1;
						if((auxxp - 1) - 500 >= m + 1 or (auxxp - 1) - 500 < 0 or auxyp - 500 >= n + 1 or auxyp - 500 < 0)
							mat[auxyp][auxxp - 1] = 1;
						if(auxxp - 500 >= m + 1 or auxxp - 500 < 0 or (auxyp - 1) - 500 >= n + 1 or (auxyp - 1) - 500 < 0)
							mat[auxyp - 1][auxxp] = 1;
							
						break;
					}
				}
				else
				{
					if(not(xp - 500 >= m + 1 or xp - 500 < 0 or yp - 500 >= n + 1 or yp - 500 < 0))	
						mat[yp][xp] = 0;
					xp += xx;
					yp += yy;
					mat[yp][xp] = 1;
				}
				/*
				mat[yp][xp] = 0;
				xp += xx;
				yp += yy;
				mat[yp][xp] = 1;
				*/			

			}
			else
				convert1(op[i], dir);
		}

		cout << xp - 500 << " " << yp - 500 << " " << dir;

		if(lost)
		{
			mat[yp][xp] = 0;
			cout << " LOST\n";
		}
		else
			cout << "\n";
	}

	return 0;
}

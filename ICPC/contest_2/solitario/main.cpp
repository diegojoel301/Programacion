#include<iostream>

using namespace std;

int main()
{
	int M, N, c = 0;

	cin >> M >> N;	

	bool m[M][N];

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
			cin >> m[i][j];
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(m[i][j])
			{
				bool sw = true;
				
				if(i - 1 >= 0)
					if(m[i - 1][j])
						sw = false;

				if(i + 1 < M)
					if(m[i + 1][j])
						sw = false;

				if(i - 1 >= 0 and j + 1 < N)
					if(m[i - 1][j + 1])
						sw = false;

				if(i - 1 >= 0 and j - 1 >= 0)
					if(m[i - 1][j - 1])
						sw = false;

				if(j - 1 >= 0)
					if(m[i][j - 1])
						sw = false;

				if(j + 1 < N)
					if(m[i][j + 1])
						sw = false;

				if(i + 1 < M and j - 1 >= 0)
					if(m[i + 1][j - 1])
						sw = false;

				if(i + 1 < M and j + 1 < N)
					if(m[i + 1][j + 1])
						sw = false;
				
				if(sw)
					c++;
			}
		}
	}
	cout << c << "\n";

	return 0;
}
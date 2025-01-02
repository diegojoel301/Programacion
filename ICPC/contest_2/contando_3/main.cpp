#include<iostream>

using namespace std;

bool verificaPrimo(int n)
{
	if(n <= 1)
		return false;

	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N, M, c = 0;
	
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0, val; j < M; j++)
		{
			cin >> val;
			if(verificaPrimo(val))
				c++;
		}
		
	}
	
	cout << c << "\n";
	return 0;
}

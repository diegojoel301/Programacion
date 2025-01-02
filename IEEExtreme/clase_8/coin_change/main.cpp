#include<bits/stdc++.h>
#define max 100

using namespace std;

int ans[max];

int findMinCoins(int coins[], int size, int value)
{
	int count = 0;

	for(int i = size - 1; i >= 0; i--)
	{
		while(value >= coins[i])
		{
			value -= coins[i];
			ans[count] = coins[i];
			count++;
		}

		if(value == 0)
			break;
	}

	return count;
}


int main()
{
	int coins[] = {1, 2, 5, 10, 20};

	int valor = 36;

	int size = sizeof(coins) / sizeof(coins[0]);

	int MinCount = findMinCoins(coins, size, valor);

	cout << "Total de monedas a necesitar: " << MinCount << "\n";
	cout << "Las monedas son: \n";
	for(int i = 0; i < MinCount; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
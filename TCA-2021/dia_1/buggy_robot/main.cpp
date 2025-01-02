#include<iostream>

using namespace std;

short int x = 0, y = 0, n, c = 0, sum = 0;

char movements[100];

int main()
{
	cin >> n;
	cin.ignore();
	cin.getline(movements, n + 1); 

	for(int i = 0; i < n; i++)
	{
		if(movements[i] == 'U')
			y++;
		if(movements[i] == 'D')
			y--;
		if(movements[i] == 'L')
			x--;
		if(movements[i] == 'R')
			x++;

	}
	cout << n - abs(x) - abs(y) << "\n";

	return 0;
}
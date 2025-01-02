#include<bits/stdc++.h>
#define M 1000001

using namespace std;

int suma(string v, int a, int b)
{
	int sum = 0, value;
	string num = "";

	for(auto x : v)
	{
		if(x == ' ')
		{
			value = stoi(num);
			if(a <= value and value <= b)
				sum += value;
			num = "";
		}
		else
			num = num + x;
	}
	value = stoi(num);
	if(a <= value and value <= b)
		sum += value;

	return sum;
}

int main()
{
	int a, b;
	char cad[M];

	while(cin >> a >> b)
	{
		cin.ignore();
		cin.getline(cad, M, '\n');

		cout << suma(cad, a, b) << "\n";
	}

	return 0;
}
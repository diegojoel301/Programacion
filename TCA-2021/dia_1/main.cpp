#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	short int n;
	cin >> n;
	vector<string> v;
	string row;

	for(int i = 0; i < n; i++)
	{
		cin >> row;
		v.push_back(row);
	}

	
	bool sw = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0, s = 0; j < n; j++)
		{
			if(j + 1 < n)
			{
				if(v[i][j + 1] == 'o')
					s++;
			}

			if(j - 1 >= 0)
			{
				if(v[i][j - 1] == 'o')
					s++;
			}

			if(i + 1 < n)
			{
				if(v[i + 1][j] == 'o')
					s++;
			}

			if(i - 1 >= 0)
			{
				if(v[i - 1][j] == 'o')
					s++;
			}

			if(s % 2 == 1)
			{
				sw = false;
				break;
			}
		}
		if(not sw)
		{
			cout << "NO\n";
			break;
		}
	}

	if(sw)
		cout << "YES\n";
	
	return 0;
}
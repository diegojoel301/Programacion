#include<bits/stdc++.h>

using namespace std;

int cantidad(vector<int> v)
{
	int key, i, c = 0;
	for(int j = 1; j < v.size(); j++)
	{
		key = v[j];
		i = j - 1;

		while(i > - 1 and v[i] > key)
		{
			v[i + 1] = v[i];
			i--;
			c++;
		}
		v[i + 1] = key;
	}
	return c;
}

int main()
{
	char vec[51];

	while(cin.getline(vec, 51))
	{
		vector<int> v;
		
		char *token = strtok(vec, " ");

		while(token != NULL)
		{
			v.push_back(stoi(token));
			token = strtok(NULL, " ");
		}
		cout << cantidad(v) << "\n";
	}
	

	return 0;
}
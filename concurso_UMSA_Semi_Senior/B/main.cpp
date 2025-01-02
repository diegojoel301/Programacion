#include<bits/stdc++.h>

using namespace std;

bool isNumber(const string& str)
{
	for(char const &c : str)
	{
		if(isdigit(c) == 0)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string cad;

	while(getline(cin, cad, '\n'))
	{
		cad += " ";
		int c = 0, val, t1 = 0, t2 = 0;
		priority_queue<int> pq;
		string aux;

		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] == ' ')
			{
				if(isNumber(aux))
					pq.push(stoi(aux));
				aux = "";
			}
			else
				aux += cad[i];
		}

		while(not pq.empty())
		{
			val = pq.top();
			if(c % 2 == 0)
				t1 += val;
			else
				t2 += val;
			c++;
			pq.pop();
		}

		cout << abs(t1 - t2) << "\n";

	}
	return 0;
}
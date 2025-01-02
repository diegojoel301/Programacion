#include<bits/stdc++.h>

using namespace std;

queue<int> q;

bool verifica()
{
	int elem, elem1, size = q.size();
	bool flag = false;

	while(size--)
	{
		elem = q.front();
		q.pop();
		elem1 = q.front();

		if(elem == elem1)
		{
			flag = true;
			q.pop();
			q.push(elem + 1);
		}
		else
		{
			q.push(elem);
		}
	}

	return flag;
}

int main()
{
	int n, value;

	cin >> n;

	while(n--)
	{
		cin >> value;
		q.push(value);
	}
	
	while(verifica());

	cout << "---------------------------------------\n";

	while(not q.empty())
	{
		int elem = q.front();
		cout << elem << "\n";
		q.pop();
	}

	return 0;
}
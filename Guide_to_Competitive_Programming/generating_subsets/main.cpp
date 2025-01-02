#include<bits/stdc++.h>

using namespace std;

vector<int> subset;
int n = 3;

void search(int k)
{
	if(k == n + 1)
	{
		for(int i = 0; i < n; i++)
			cout << subset[i] << " ";
		cout << "\n";
	}
	else
	{
		subset.push_back(k);
		search(k + 1);
		subset.pop_back();
		// don't include k in the subset
		search(k + 1);
	}
}

int main()
{
	//search(1);
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n = 4;

vector<int> permutation;
bool chosen[4];

void search()
{
	if(permutation.size() == n)
	{
		for(int i = 1; i <= n; i++)
		{
			if(chosen[i])
				cout << permutation[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(chosen[i])
				continue;

			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

bool state[10];
int A[3] = {1, 2, 3};

void mysearch(vector<int> v)
{
	if(v.size() == n)
	{
		for(int i = 0; i < n; i++)
		{
			if(state[i])
				cout << v[i] << " ";
		}
		cout << "\n";
	}
	
	for(int i = 0; i < n; i++)
	{
		if(not state[i])
		{
			state[i] = true;
			mysearch(v);
			v.push_back(A[i]);
			mysearch(v);
			state[i] = false;
			v.pop_back();
		}
	}
	
}

int main()
{
	n = 3;
	//search();
	vector<int> v;
	mysearch(v);
	return 0;
}
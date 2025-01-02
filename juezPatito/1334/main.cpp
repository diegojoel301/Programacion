#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	if(a.second < b.second)
		return a.second < b.second;
	if(a.second == b.second)
		return a.first < b.first;
	return 0;
}

int sd(int n)
{
	if(n > 0)
		return sd(n / 10) + (n % 10);
	else
		return 0;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	
	for(int i = 0, value; i < N; i++)
	{
		cin >> value;
		pair<int, int> aux(value, sd(value));
		v.push_back(aux);
	}

	sort(v.begin(), v.end(), sortbysec);

	for(int i = 0; i < N - 1; i++)
		cout << v.at(i).first << " ";
	cout << v.at(N - 1).first << "\n";
	return 0;
}
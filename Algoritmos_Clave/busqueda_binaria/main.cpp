#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> v, int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r - l) / 2;

		if(v[mid] == x)
			return mid;

		if(v[mid] > x)
			return binarySearch(v, l, mid - 1, x);

		return binarySearch(v, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	vector<int> v = {6, 4, 3, 5, 2, 8, 9, 3, 2, 1};

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";

	int x = 10;
	int n = v.size();

	int result = binarySearch(v, 0, n - 1, x);

	cout << result << "\n";

	return 0;
}
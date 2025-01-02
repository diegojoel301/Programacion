#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int n) 
{ 
	int max_so_far = INT_MIN, ans = 0; 
	for (int i = n - 1; i >= 0; i--) 
	{ 
		if (arr[i] >= max_so_far) 
		{ 
			max_so_far = arr[i]; 
			ans++;
		} 
	}
	return ans;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int t;

	cin >> t;

	while(t--)
	{
		int n;

		cin >> n;

		int arr[n];

		for(int i = 0; i < n; i++) cin >> arr[i];

		cout << n - find(arr, n) << "\n";
	}
		

	return 0;
}
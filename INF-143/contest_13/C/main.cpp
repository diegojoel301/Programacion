#include<bits/stdc++.h>

using namespace std;

int getMid(int s, int e)
{
	return s + (e - s) / 2;
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss and qe >= se)
		return st[si];

	if(se < qs or ss > qe)
		return 0;

	int mid = getMid(ss, se);

	return getSumUtil(st, ss, mid, qs, qe, 2*si + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2*si + 2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if(i < ss or i > se)
		return;

	st[si] = st[si] + diff;

	if(se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2*si + 2);
	}
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
	if(i < 0 or i > n - 1)
		return;

	int diff = new_val - arr[i];

	arr[i] = new_val;

	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe)
{
	if(qs < 0 or qe > n - 1 or qs > qe)
		return -1;
	return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);

	st[si] = constructSTUtil(arr, ss, mid, st, si*2 + 1) + constructSTUtil(arr, mid + 1, se, st, si*2 + 2);

	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));

	int max_size = 2 * (int) pow(2, x) - 1;

	int *st = new int[max_size];

	constructSTUtil(arr, 0, n - 1, st, 0);

	return st;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--)
	{
		int n, q, x, y;

		cin >> n >> q;

		int arr[n];

		for(int i = 0; i < n; i++)
			cin >> arr[i];

		int *st = constructST(arr, n);

		while(q--)
		{
			char op;

			cin >> op;

			cin >> x >> y;

			if(op == 'P')
				cout << getSum(st, n, x - 1, y - 1) << "\n";
			else
				updateValue(arr, st, n, x - 1, y);
		}
	}

	return 0;
}
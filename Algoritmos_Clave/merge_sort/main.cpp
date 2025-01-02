#include<bits/stdc++.h>

using namespace std;

vector<int> v;

void merge_sort(int L, int R)
{
	if(L == R)
		return;

	int mid = (L + R) / 2;
	merge_sort(L, mid);
	merge_sort(mid + 1, R);

	deque<int> Left, Right;

	// cola L para la izquierda
	for(int i = L; i <= mid; i++)
		Left.push_back(v[i]);

	// cola R para la derecha
	for(int i = mid + 1; i <= R; i++)
		Right.push_back(v[i]);

	for(int i = L; i <= R; i++)
	{
		if(Left.size() == 0)
		{
			v[i] = Right.front();
			Right.pop_front();
		}
		else if(Right.size() == 0)
		{
			v[i] = Left.front();
			Left.pop_front();
		}
		else
		{
			if(Right.front() < Left.front())
			{
				v[i] = Right.front();
				Right.pop_front();
			}
			else
			{
				v[i] = Left.front();
				Left.pop_front();
			}
		}
	}
}

int main()
{
	int n;

	cin >> n;

	for(int i = 0, x; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	merge_sort(0, n - 1);

	for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}
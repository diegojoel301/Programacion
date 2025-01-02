#include<bits/stdc++.h>

using namespace std;

int maxHistogram(int input[25], int N)
{
	deque<int> stack;

	int maxArea = 0;
	int area = 0;
	int i;

	for(i = 0; i < N;)
	{
		if(stack.empty() or input[stack.front()] <= input[i])
			stack.push_front(i++);
		else
		{
			int top = stack.front();
			stack.pop_front();

			if(stack.empty())
				area = input[top] * i;
			else
				area = input[top] * (i - stack.front() - 1);

			if(area > maxArea)
				maxArea = area;
		}
	}

	while(not stack.empty())
	{
		int top = stack.front();
		stack.pop_front();

		if(stack.empty())
			area = input[top] * i;
		else
			area = input[top] * (i - stack.front() - 1);

		if(area > maxArea)
			maxArea = area;
	}
	return maxArea;
}

int maxSubMatriz(bool mat[25][25], int N)
{
	int aux[N], maxArea = 0;
	memset(aux, 0, sizeof(aux));
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(mat[i][j] != 0)
				aux[j] += 1;
			else
				aux[j] = 0;
		}

		int areaH = maxHistogram(aux, N);

		if(areaH > maxArea)
			maxArea = areaH;
	}
	
	
	return maxArea;
}

int main()
{
	int N, t;
	cin >> t;
	while(t--)
	{
		cin >> N;
		bool mat[25][25];

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cin >> mat[i][j];
		}

		cout << maxSubMatriz(mat, N) << "\n";	
	}
	return 0;
}
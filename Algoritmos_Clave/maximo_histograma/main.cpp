#include<bits/stdc++.h>

using namespace std;

int maxHistogram(int input[10], int N)
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

int main()
{
	int N = 10;

	int v[N] = {6, 1, 5, 4, 5, 2, 6, 2, 3};

	cout << maxHistogram(v, N) << "\n";
	return 0;
}
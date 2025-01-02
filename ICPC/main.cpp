#include<bits/stdc++.h>

using namespace std;
struct Stack
{
	int st[100010];
	int end;

	Stack()
	{
		end = -1;
	}

	bool empty()
	{
		return end == -1;
	}

	void push(int t)
	{
		st[++end] = t;
	}

	int top()
	{
		return st[end];
	}
	void pop()
	{
		end--;
	}

};

struct Queue
{
	int q[100010];
	int start, end;
	Queue()
	{
		start = end = 0;
	}

	bool isEmpty()
	{
		return start == end;
	}

	void push(int t)
	{
		q[end++] = t;
	}

	int front()
	{
		return q[start];
	}

	void pop()
	{
		start++;
	}
};

int main()
{
	Queue q;

	q.push(2);
	q.push(4);
	q.push(8);
	q.push(9);
	q.push(12);

	while(not q.isEmpty())
	{
		int u = q.front();
		q.pop();
		cout << u << "\n";
	}

	Stack st;

	st.push(2);
	st.push(4);
	st.push(8);
	st.push(9);
	st.push(12);

	while(not st.empty())
	{
		int u = st.top();
		st.pop();
		cout << u << "\n";
	}

	

	return 0;
}
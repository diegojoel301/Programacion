#include <bits/stdc++.h>

using namespace std;

struct MinHeap
{
	int mh[100010];
	int last = 0;

	MinHeap(){}

	int top()
	{
		return mh[1];
	}

	bool empty()
	{
		return last == 0;
	}

	void siftUp()
	{
		int aux = last;

		while (aux >= 1 and mh[aux / 2] < mh[aux])
		{
			swap(mh[aux / 2], mh[aux]);
			aux >>= 1;
		}
	}

	void siftDown()
	{
		int root = 1;

		while(root < last)
		{
			int le = root * 2;
			int ri = root * 2 + 1;
			int pos = -1;

			if(le <= last and mh[le] < mh[root]) pos = le;

			if(pos != -1)
			{
				if(ri <= last and mh[pos] > mh[ri]) { pos = ri; }
			}
			else if(ri <= last and mh[ri] < mh[root]) pos = ri;

			if(pos != -1)
			{
				swap(mh[root], mh[pos]);
				root = pos;
			}
			else
				break;
		}
	}

	void insert(int u)
	{
		mh[++last] = u;
		siftUp();
	}

	void pop()
	{
		mh[1] = mh[last--];
		siftDown();
	}
};

int main()
{
	MinHeap mh;

	mh.insert(1);
	mh.insert(7);
	mh.insert(2);
	mh.insert(9);
	mh.insert(8);

	while(not mh.empty())
	{
		int u = mh.top();
		mh.pop();
		cout << u << "\n";
	}

	return 0;
}
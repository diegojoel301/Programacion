#include<iostream>
#include <math.h>

using namespace std;

bool verify_ugly(int x)
{
	bool flag = false;
	if(x % 2 == 0 or x % 3 == 0 or x % 5 == 0)
		flag = true;
	
	for(int i = 6; i < x; i++)
	{
		if(x % i == 0)
		{
			flag = false;
			break;
		}
	}

	return flag;

}

int ugly_N(int n)
{
	int c = 0, x = 1;

	while(n != c)
	{
		if(verify_ugly(x))
			c++;
		if(n == c)
			break;
		x++;
	}

	return x;
}

int FindUgly(int n)
{
	int* ugly = new int[n];

	ugly[0] = 1; // por convencion

	int index2 = 0, index3 = 0, index5 = 0, index = 1;

	while(index < n)
	{
		int val = min( min(ugly[index2] * 2, ugly[index3] * 3), ugly[index5] * 5 );

		if(val == ugly[index2] * 2)
			index2++;
		if(val == ugly[index3] * 3)
			index3++;
		if(val == ugly[index5] * 5)
			index5++;
		ugly[index++] = val;
	}
	int result = ugly[n - 1];

	delete[] ugly;

	return result;
}

int main()
{
	int n = 1;
	for(int i = 1; i <= 20; i++)
		cout << ugly_N(i - 1) << "\n";
}
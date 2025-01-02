#include<iostream>
#include<vector>
//#include<math.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	//retirar el vector es en si opcional como tambien adicionarlo
	for(int j = 0; j < T; j++)
	{
		int N, my = -1, mn = 999999999, pmy, pmn, tmp;

		cin >> N;

		//vector<int> v;

		for(int i = 0, value; i < N; i++)
		{
			cin >> value;
			//v.push_back(value);

			if(my < value)
			{
				my = value;
				pmy = i;
			}
			if(mn > value)
			{
				mn = value;
				pmn = i;
			}
		}

		if(pmn > pmy)
		{
			tmp = pmn;
			pmn = pmy;
			pmy = tmp;
		}

		cout << min(  min(  (pmn + 1) + (pmy - pmn), (pmn + 1) + (N - pmy)  ),  (pmy - pmn) + (N - pmy) )<< "\n";
	}
	return 0;
}

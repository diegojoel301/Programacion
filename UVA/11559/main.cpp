#include<iostream>

using namespace std;

int main()
{
	int N, B, H, W;

	while(cin >> N >> B >> H >> W)
	{
		int finalPrice = 99999999, p;

		for(int i = 0; i < H; i++)
		{
			cin >> p;
			bool sw = true;

			for(int j = 0, w = -1; j < W; j++)
			{
				cin >> w;

				if(w < N)
					sw = false;
			}

			if(sw)
			{
				if(N * p <= B)
				{
					if(finalPrice > N * p)
						finalPrice = N * p;
				}
			}

		}

		if(finalPrice <= B)
			cout << finalPrice << "\n";
		else
			cout << "stay home\n";
	}
	return 0;
}

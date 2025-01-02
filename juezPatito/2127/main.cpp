#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, e, v1, v2, cv1 = 0, cv2 = 0, sv1 = 0, sv2 = 0;

	cin >> n;

	while(n--)
	{
		cin >> e >> v1 >> v2;

		sv1 += v1;
		sv2 += v2;

		if(v1 > v2)
			cv1++;
		else if(v2 > v1)
			cv2++;

	}

	if(cv1 > cv2 and sv1 > sv2)
		cout << "1\n";
	else if(cv2 > cv1 and sv2 > sv1)
		cout << "2\n";
	else
		cout << "0\n";

	return 0;
}
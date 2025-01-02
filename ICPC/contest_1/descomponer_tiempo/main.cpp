#include<iostream>

using namespace std;

int main()
{
	int N, hrs, min, seg;

	cin >> N;

	hrs = N / 3600;
	min = (N - (hrs * 3600)) / 60;
	seg = (N - (hrs * 3600) - (min * 60));

	cout << hrs << " " << min << " " << seg << "\n";

	return 0;
}
#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int Xp, Zlb, Uc, Pe;

	cin >> Xp;

	Zlb = Xp / 240;
	Uc = (Xp - (Zlb * 240)) / 12;
	Pe = (Xp - (Zlb * 240) - (Uc *12));

	cout << "(" << Zlb << ", " << Uc << ", " << Pe << ")\n";
	return 0;
}
#include<bits/stdc++.h>
#define M 32

using namespace std;

int main()
{
	bitset<M> bset1;
	bitset<M> bset2(20);

	bitset<M> bset3(string("1100"));

	cout << bset1 << "\n";
	cout << bset2 << "\n";
	cout << bset3 << "\n";
	cout << "\n";

	bitset<8> set8;

	set8[1] = 1;
	set8[4] = set8[1];

	cout << set8 << "\n";

	int numberof1 = set8.count();

	int numberof0 = set8.size() - numberof1;

	cout << set8 << " tiene " << numberof1 << " unos y " << numberof0 << " ceros\n";

	cout << set8.set(4, 0) << "\n"; //cambia ese bit

	cout << set8.set(4) << "\n"; //setea esa posicion por un 1

	cout << set8.reset(2) << "\n";

	cout << set8.reset() << "\n";

	cout << set8.flip(2) << "\n"; // negacion de ese bit
	cout << set8.flip() << "\n"; // complemento a 1 de el conjunto

	int num = 100;

	cout << "\nDecimal number: " << num << " Binary equivalent: " << bitset<8>(num) << "\n";

	return 0;
}

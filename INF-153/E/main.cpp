#include<bits/stdc++.h>

using namespace std;

bool verifica()
{
	int a, b, c;

	cin >> a >> b >> c;

	vector<int> dan = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<int> dab = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if((c % 4 != 0 or c % 100 == 0) and (c % 4 != 0 or c % 400 != 0)) goto condicion_1;
	{
		if(b > 12 or b < 1) goto condicion_2;
		{
			if(a > dab[b - 1] or a < 0) goto condicion_3;
				return true;
			condicion_3: return false;
		}
		condicion_2: return false;
	}
	condicion_1:
		if(b > 12 or b < 1) goto condicion_5;
		{
			if(a > dan[b - 1] or a < 0) goto condicion_4;
				return true;
			condicion_4: return false;
		}
		condicion_5: return false;

	return false;
 
	/*
	if((c % 4 == 0 and c % 100 != 0) or (c % 4 == 0 and c % 400 == 0))
	{
		if(b <= 12 or b >= 1)
		{
			if(a <= dab[b - 1])
				return true;
			else
				return false;
		}
		else if(b > 12)
		{
			return false;
		}
	}
	else
	{
		if(b <= 12 or b >= 1)
		{
			if(a <= dan[b - 1])
				return true;
			else
				return false;
		}
		else if(b > 12)
		{
			return false;
		}	
	}
	return false;
	*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	n--;

	ciclo:
		if(not verifica()) goto condicion_6;
		{
			cout << "Fecha correcta\n";
			n--;
			goto ciclo;
		}
		condicion_6:
		cout << "Fecha incorrecta\n";
		
	
	if(n--) goto ciclo;

	return 0;
}
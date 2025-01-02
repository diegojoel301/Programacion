#include<iostream>

using namespace std;

int SZ, p;

void buscaEspiral();

int main()
{
	/*
	while(cin >> SZ >> p;)
	{
		if(SZ != 0 and p != 0)
			break;
		//buscaEspiral(p);
		if(p != 1)
			buscaEspiral(p);
		else
			cout << "Line = " << (SZ % 2) + (SZ / 2)<< ", column = " << (SZ % 2) + (SZ / 2)<<".\n";
	}*/
	SZ = 5;
	p = 2;
	buscaEspiral();

	return 0;
}
/*
void buscaEspiral(int p)
{
	for(int j = 1, fc = 0, x = SZ * SZ, fil = 0, col = SZ - 1; j <= SZ / 2; j++, fc += 2, fil++, col--)
	{
		for(int i = 0; i < SZ - fc; i++, x--, fil++)
		{
			if(x == p)
			{
				cout << "Line = " << SZ - fil<< ", column = " << col + 1<<".\n";
				return;
			}
		}
		fil--;
		col--;
		for(int i = 0; i < SZ - ((j * 2) - 1); i++, x--, col--)
		{
			if(x == p)
			{
				cout << "Line = " << SZ - fil<< ", column = " << col + 1<<".\n";
				return;
			}
		}
		col++;
		fil--;
		for(int i = 0; i < SZ - ((j * 2) - 1); i++, x--, fil--)
		{
			if(x == p)
			{
				cout << "Line = " << SZ - fil<< ", column = " << col + 1<<".\n";
				return;
			}
		}
		fil++;
		col++;

		for(int i = 0; i < SZ - (j * 2); i++, x--, col++)
		{
			if(x == p)
			{
				cout << "Line = " << SZ - fil<< ", column = " << col + 1<<".\n";
				return;
			}
		}
	}
}
*/
void buscaEspiral()
{
	for(int i = 1; i <= SZ; i += 2)
	{
		if()
		if((i - 2) * (i - 2) < p < i * i)
	}
}
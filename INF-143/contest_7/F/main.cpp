#include<bits/stdc++.h>

using namespace std;

int main()
{
	string entrada, num, num1, num2;

	while(getline(cin, entrada, '\n'))
	{

		if(entrada[entrada.size() - 1] != ' ')
			entrada += " ";

		double costo_total = 0, precio_total = 0, ganancia;

		for(int i = 0; i < entrada.size(); i++)
		{
			if(entrada[i] == ' ')
			{
				if(i == 6)
					precio_total += stod(num);
				else if(i == entrada.size() - 1)
					costo_total += stod(num);
				else
				{
					costo_total += stod(num.substr(0, 6));
					precio_total += stod(num.substr(7, num.size()));
				}

				num = "";
			}
			else
				num += entrada[i];
		}
		ganancia = 100 * abs(costo_total - precio_total) / precio_total;
		cout << floor(ganancia) << "\n";
	}

	return 0;
}
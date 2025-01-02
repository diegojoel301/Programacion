#include<iostream>

using namespace std;

void solucion()
{
	double pago_inicial, monto_prestamo, dec[101];
	int duracion_meses_prestamo, nro_dep, pos;

	while(true)
	{
		cin >> duracion_meses_prestamo;
		cin >> pago_inicial >> monto_prestamo;
		cin >> nro_dep;

		if(duracion_meses_prestamo < 0)
			break;

		int pos;
		double x;

		while(nro_dep--)
		{
			cin >> pos >> x;
			for(int i = pos; i < 101; i++) dec[i] = x;	
		}

		int ahora = 0;

		double va = (monto_prestamo + pago_inicial) * (1 - dec[ahora]);
		double dd = monto_prestamo;
		double cuota = monto_prestamo / duracion_meses_prestamo;

		while(va < dd)
		{
			ahora++;
			dd = dd - cuota;
			
			va = va * (1 - dec[ahora]);
			
		}

		cout << ahora << " month";
		if(ahora > 1)
			cout << "s";
		cout << "\n";
	}
}
int main()
{
	solucion();
	return 0;
}
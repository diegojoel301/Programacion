#include<bits/stdc++.h>

using namespace std;

void mostrar(vector<int> v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

void combinacionesSuma(int numero, vector<int> v, int suma)
{
	if(suma == numero)
	{
		mostrar(v);

		return;
	}

	for(int i = 1; i <= numero; i++)
	{
		suma += i;
		if(suma <= numero)
		{
			v.push_back(i);
			combinacionesSuma(numero, v, suma);
			// el retroseso es importante
			v.pop_back(); // vuelta hacia atras: eliminamos aquel elemento que ya hayamos usado
		}
		suma -= i; //vuelta hacia atras: se restara 
	}
}

void combinacionesSuma1(int numero, vector<int> v, int suma)
{
	for(int i = 1; i <= numero; i++)
	{
		if(suma == numero)
		{
			mostrar(v);
			//break;
		}
		suma += i;
		
		if(suma <= numero)
		{
			v.push_back(i);

			for(int j = 1; j <= numero; j++)
			{
				if(suma == numero)
				{
					mostrar(v);
					//break;
				}
				suma += j;

				if(suma <= numero)
				{
					v.push_back(j);
					for(int k = 1; k <= numero; k++)
					{
						if(suma == numero)
						{
							mostrar(v);
							//break;
						}
						suma += k;

						if(suma <= numero)
						{
							v.push_back(j);
							for(int m = 1; m <= numero; m++)
							{
								if(suma == numero)
								{
									mostrar(v);
									//break;
								}
								suma += m;

								if(suma <= numero)
								{
									v.push_back(m);
									for(int l = 1; l <= numero; l++)
									{
										if(suma == numero)
										{
											mostrar(v);
											//break;
										}
										suma += l;

										if(suma <= numero)
										{
											v.push_back(l);
											//otro for mas
											v.pop_back();
										}
										suma -= l;
										
									}
									v.pop_back();
								}
								suma -= m;
								
							}
							v.pop_back();
						}
						suma -= k;
						
					}
					v.pop_back();
				}
				suma -= j;
				
			}

			v.pop_back();
		}
		suma -= i;

	}
}

int main()
{
	int n = 5;
	vector<int> v;

	//combinacionesSuma(n, v, 0);
	combinacionesSuma1(n, v, 0);

	return 0;
}